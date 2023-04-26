#include <array>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <regex>
#include <variant>

#include "ZHLLexer.h"
#include "ZHLParser.h"
#include "ZHLParserBaseListener.h"
#include "ZHLParserBaseVisitor.h"

namespace fs = std::filesystem;

enum PointerKind {
    LREF,
    RREF,
    POINTER
};

std::string PointerKindToString(PointerKind kind) {
    switch (kind) {
    case LREF:
        return "&";

    case RREF:
        return "&&";

    case POINTER:
        return "*";
    }

    return "";
}

struct PointerDecl {
    bool _const;
    PointerKind _kind;

    std::string ToString() const {
        std::ostringstream str;
        str << PointerKindToString(_kind);

        if (_const) {
            str << " const ";
        }

        return str.str();
    }
};

enum Signedness {
    SIGNED,
    UNSIGNED
};

enum Length {
    LONG,
    LONGLONG,
    SHORT
};

enum BasicTypes {
    CHAR,
    INT,
    BOOL,
    VOID,
    FLOAT,
    DOUBLE
};

std::string BasicTypeToString(BasicTypes type) {
    switch (type) {
    case CHAR:
        return "char";

    case INT:
        return "int";

    case BOOL:
        return "bool";

    case VOID:
        return "void";

    case FLOAT:
        return "float";

    case DOUBLE:
        return "double";

    default:
        throw std::runtime_error("Invalid basic type");
    }
}

struct BasicType {
    std::optional<Signedness> _sign;
    std::optional<Length> _length;
    BasicTypes _type;

    std::string ToString() const {
        std::ostringstream res;
        if (_sign) {
            switch (*_sign) {
            case SIGNED:
                res << "signed ";
                break;

            case UNSIGNED:
                res << "unsigned ";
                break;
            }
        } else {
            if (_type == BasicTypes::INT || _type == BasicTypes::CHAR) {

            }
        }

        if (_length) {
            switch (*_length) {
            case LONG:
                res << "long";
                break;

            case LONGLONG:
                res << "long long";
                break;

            case SHORT:
                res << "short";
            }
        }

        res << BasicTypeToString(_type);

        return res.str();
    }
};

struct FunctionPtr;
struct Struct;

struct Type {
    bool _const = false;
    bool _array = false;
    size_t _arraySize = 0;
    // Basic type represents the char, int, bool etc. types and their composites.
    // std::string represents a type that is composed of a single word (minus pointers) that
    // can be a typedef or the name of a class.
    // unique_ptr<Struct> represent a type defined in a structure.
    // unique_ptr<FunctionPtr> represents a pointer to function. unique_ptr used because FunctionPtr
    // contains a Type, which would create an infinite structure if it was added here without an
    // indirection.
    // Nested names are not allowed because properly processing them would require interpreting the files.
    std::variant<BasicType, FunctionPtr*, Struct*, std::string> _name;
    std::vector<PointerDecl> _pointerDecl;

    ~Type();

    bool IsPointer() const {
        return !_pointerDecl.empty();
    }

    std::string ToString() const;
};

struct FunctionPtr {
    Type _ret;
    std::vector<Type> _parameters;
};

enum NamespaceKind {
    GLOBAL,
    CLASS
};

enum FunctionKind {
    FUNCTION,
    METHOD
};

enum Registers {
    EAX,
    EBX,
    ECX,
    EDX,
    EDI,
    ESI,
    ESP,
    EBP,
    XMM0,
    XMM1,
    XMM2,
    XMM3,
    XMM4,
    XMM5,
    XMM6,
    XMM7,
    MAX
};

static std::string RegisterToString(Registers reg) {
    switch (reg) {
    case EAX:
        return "eax";

    case EBX:
        return "ebx";

    case ECX:
        return "ecx";

    case EDX:
        return "edx";

    case EDI:
        return "edi";

    case ESI:
        return "esi";

    case ESP:
        return "esp";

    case EBP:
        return "ebp";

    case XMM0:
    case XMM1:
    case XMM2:
    case XMM3:
    case XMM4:
    case XMM5:
    case XMM6:
    case XMM7:
        return std::string("xmm") + std::to_string(reg - XMM0);

    default: {
        std::ostringstream err;
        err << "Invalid register ID " << reg;
        throw std::runtime_error(err.str());
    }
    }
}

enum FunctionQualifiers {
    STATIC = 1 << 0,
    VIRTUAL = 1 << 1,
    CLEANUP = 1 << 2
};

enum CallingConventions {
    CDECL,
    STDCALL,
    FASTCALL,
    THISCALL
};

std::string CallingConventionToString(CallingConventions convention) {
    switch (convention) {
    case CDECL:
        return "__cdecl";

    case STDCALL:
        return "__stdcall";

    case FASTCALL:
        return "__fastcall";

    case THISCALL:
        return "__thiscall";

    default:
        throw std::runtime_error("Invalid calling convention");
    }
}

struct FunctionParam {
    Type _type;
    std::string _name;
    std::optional<Registers> _reg;

    std::string ToString() const {
        std::ostringstream s;
        s << _type.ToString() << " " << _name;
        if (_reg) {
            s << "<" << RegisterToString(*_reg) << ">";
        }

        return s.str();
    }
};

struct Function {
    uint32_t _qualifiers;
    FunctionKind _kind;
    std::optional<CallingConventions> _convention;
    Type _ret;
    std::string _name;
    std::vector<FunctionParam> _params;

    bool IsVirtual() const {
        return _qualifiers & VIRTUAL;
    }

    bool IsCleanup() const {
        return _qualifiers & CLEANUP || (_convention && *_convention == CDECL);
    }

    bool IsStatic() const {
        return _qualifiers & STATIC;
    }

    std::string ToString() const;
};

struct Variable {
    Type _type;
    std::string _name;
};

struct Signature {
    std::string _sig;
    Function _function;
};

struct VariableSignature {
    std::string _sig;
    Variable _variable;
};

typedef std::variant<Signature, VariableSignature> SignatureV;

struct Namespace {
    // std::vector<Namespace> _children;
    std::vector<Function> _functions;
    std::vector<Variable> _fields;
    std::vector<Signature> _signatures;
};

enum Visibility {
    PUBLIC,
    PRIVATE,
    PROTECTED
};

struct Struct {
    Namespace _namespace;
    std::string _name;
    /*
     * A struct is pending if its name has been encountered but no definition has 
     * been found yet. This can happen if the name is used as the return type of 
     * a function, or used as a dependency.
     * If a struct is still pending once all files have been processed, the name is 
     * considered invalid and discarded.
     */
    bool _pending = true;

    std::string ToString() const {
        return _name;
    }

    std::set<Struct*> _deps;
    std::set<std::pair<Struct*, Visibility>> _parents;
};

std::string Type::ToString() const {
    std::ostringstream res;
    if (_const) {
        res << "const ";
    }

    if (std::holds_alternative<BasicType>(_name)) {
        res << std::get<BasicType>(_name).ToString();
    } else if (std::holds_alternative<Struct*>(_name)) {
        res << std::get<Struct*>(_name)->ToString();
    }

    if (_array) {
        res << "[" << _arraySize << "] ";
    }

    for (PointerDecl const& decl: _pointerDecl) {
        res << decl.ToString() << " ";
    }

    return res.str();
}

Type::~Type() {
    if (std::holds_alternative<Struct*>(_name)) {
        // delete std::get<Struct*>(_name);
        _name = (Struct*)0;
    } else if (std::holds_alternative<FunctionPtr*>(_name)) {
        // delete std::get<FunctionPtr*>(_name);
        _name = (FunctionPtr*)0;
    }
}

std::string Function::ToString() const {
    std::ostringstream str;
    str << "Function " << _name << std::endl;
    str << "\tqualifiers = ";
    if (_qualifiers == 0) {
        str << "none";
    } else {
        if (IsVirtual()) {
            str << "virtual ";
        } else if (IsStatic()) {
            str << "static ";
        }

        if (IsCleanup()) {
            str << "cleanup ";
        }
    }
    str << std::endl;
    str << "\ttype = " << _ret.ToString() << std::endl;
    if (_convention) {
        str << "\tconvention = " << CallingConventionToString(*_convention) << std::endl;
    }
    str << "\tparams = " << std::endl;
    for (FunctionParam const& param: _params) {
        str << "\t\t" << param.ToString() << std::endl;
    }

    return str.str();
}

struct Array {
    std::string _name;
    size_t _size;
};

typedef std::variant<std::string, Array> FullNameV;

typedef std::string GenericCode;

class ErrorLogger { //: public std::ostringstream {
public:
    struct EndToken { };
    static EndToken _end;

    ~ErrorLogger() {
        for (std::string const& err: _errors) {
            std::cerr << err << std::endl;
        }
    }

    template<typename T>
    ErrorLogger& operator<<(T const& t) {
        _buf << t;
        return *this;
    }

    static ErrorLogger& endl(ErrorLogger& logger) {
        logger.newline();
        return logger;
    }

    static ErrorLogger& error(ErrorLogger& logger) {
        logger.log_error();
        return logger;
    }

    static ErrorLogger& warn(ErrorLogger& logger) {
        logger.log_warn();
        return logger;
    }

    void log_error() {
        _buf << "[ERROR] ";
        _errored = true;
    }

    void log_warn() {
        _buf << "[WARN] ";
    }

    ErrorLogger& operator<<(ErrorLogger& (*v)(ErrorLogger&)) {
        return v(*this);
    }

    ErrorLogger& operator<<(EndToken const& token) {
        _errors.push_back(_buf.str());
        _buf.str("");
        _buf.clear();
        return *this;
    }

    void newline() {
        _buf << std::endl;
    }

    bool IsErrored() {
        return _errored;
    }

private:
    std::vector<std::string> _errors;
    std::ostringstream _buf;
    bool _errored = false;
};

ErrorLogger::EndToken ErrorLogger::_end;

class Parser : public ZHLParserBaseVisitor {
public:
    Parser(std::map<std::string, Struct*>* types) : _types(types) {

    }

    virtual std::any visitZhl(ZHLParser::ZhlContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitFunction(ZHLParser::FunctionContext* ctx) override {
        Function fn;
        _currentFunction = &fn;

        std::vector<std::string> parts = std::any_cast<std::vector<std::string>>(visit(ctx->nestedName()));
        fn._name = MergeNameParts(parts);

        std::optional<std::string> convention;
        if (auto node = ctx->CallingConvention()) {
            convention = node->getText();
            if (convention == "__stdcall") {
                fn._convention = CallingConventions::STDCALL;
            }
            else if (convention == "__fastcall") {
                fn._convention = CallingConventions::FASTCALL;
            }
            else if (convention == "__cdecl") {
                fn._convention = CallingConventions::CDECL;
            }
            else if (convention == "__thiscall") {
                if (!_currentStruct) {
                    if (ctx->nestedName()->Name().size() == 1) {
                        _errors << ErrorLogger::error <<  "__thiscall convention applied to non member function " << fn._name << ErrorLogger::_end;
                        // exit(-1);
                    }
                    fn._convention = CallingConventions::THISCALL;
                } else {
                    fn._convention = CallingConventions::THISCALL;
                }
            }
        }

        for (antlr4::tree::TerminalNode* x : ctx->Qualifier()) {
            std::string text = x->getText();
            if (text == "virtual") {
                if (fn.IsVirtual()) {
                    WarnRepeatedFunctionQualifier(fn._name, text);
                } else {
                    fn._qualifiers |= FunctionQualifiers::VIRTUAL;
                }
            }
            else if (text == "static") {
                if (fn.IsStatic()) {
                    WarnRepeatedFunctionQualifier(fn._name, text);
                }
                else {
                    fn._qualifiers |= FunctionQualifiers::STATIC;
                }
            }
            else if (text == "cleanup") {
                if (fn.IsCleanup() && !fn._convention) {
                    WarnRepeatedFunctionQualifier(fn._name, text);
                } else if (fn._convention) {
                    CallingConventions convention = *fn._convention;
                    if (convention != CDECL) {
                        _errors << ErrorLogger::error << "cleanup specified on non cdecl (" << CallingConventionToString(convention) << ") function " << GetCurrentFunctionQualifiedName(fn._name) << ErrorLogger::_end;
                    } else {
                        _errors << ErrorLogger::warn << "cleanup specified on cdecl function " << GetCurrentFunctionQualifiedName(fn._name) << ErrorLogger::_end;
                    }
                } else {
                    fn._qualifiers |= FunctionQualifiers::CLEANUP;
                }
            }

            fn._ret = std::any_cast<Type>(visit(ctx->type()));
        }

        if (fn.IsVirtual() && fn.IsStatic()) {
            _errors << ErrorLogger::error << "static and virtual qualifiers applied together to function " << GetCurrentFunctionQualifiedName(fn._name) << ErrorLogger::_end;
            // exit(-1);
        }

        if (fn.IsStatic() && fn._convention && fn._convention == CallingConventions::THISCALL) {
            _errors << ErrorLogger::error << "__thiscall convention applied to static function " << GetCurrentFunctionQualifiedName(fn._name) << ErrorLogger::_end;
            // exit(-1);
        }

        if (parts.size() > 1) {
            Namespace& nm = GetStructByName(parts.front())->_namespace;
            nm._functions.push_back(fn);
        }

        if (auto args = ctx->funArgs()) {
            fn._params = std::any_cast<std::vector<FunctionParam>>(visit(ctx->funArgs()));

            if (fn._convention) {
                for (FunctionParam const& param: fn._params) {
                    if (param._reg) {
                        _errors << ErrorLogger::warn << "Calling convention " << CallingConventionToString(*fn._convention) << " specified on function " << GetCurrentFunctionQualifiedName(fn._name) <<
                            ", you cannot specify a register on a parameter (specified "  << RegisterToString(*param._reg) << " on parameter " << param._name << ")" << ErrorLogger::_end;
                    }
                }
            }
        }

        _currentFunction = nullptr;
        return fn;
    }

    virtual std::any visitReference(ZHLParser::ReferenceContext* ctx) override {
        Variable var;
        _currentVariable = &var;

        var._name = ctx->Name()->getText();
        var._type = std::any_cast<Type>(visit(ctx->type()));

        _currentVariable = nullptr;
        return var;
    }

    /// _currentFunction assumed not null
    virtual std::any visitFunArgs(ZHLParser::FunArgsContext* ctx) override {
        std::vector<FunctionParam> params;
        typedef std::pair<bool, std::vector<unsigned int>> RegUse;
        std::array<RegUse, Registers::MAX> state = { { { false,  {} } } };

        int i = 0;
        for (ZHLParser::FunArgContext* arg : ctx->funArg()) {
            FunctionParam param = std::any_cast<FunctionParam>(visit(arg));
            if (param._reg) {
                RegUse& use = state[*param._reg];
                use.first = true;
                use.second.push_back(i);
            }
            params.push_back(param);
            ++i;
        }

        i = 0;
        for (RegUse const& use : state) {
            if (use.first) {
                if (use.second.size() > 1) {
                    _errors << ErrorLogger::error << "Register " << RegisterToString((Registers)i) << " used on multiple parameters in function " << GetCurrentFunctionQualifiedName(_currentFunction->_name) << ErrorLogger::endl;
                    _errors << "\tInfringing parameters are ";
                    for (int paramPos: use.second) {
                        FunctionParam const& param = params[paramPos];
                        _errors << param._name << " (param " << i << ")";
                        if (paramPos != use.second.back()) {
                            _errors << ", ";
                        }
                    }
                    _errors << ErrorLogger::_end;
                }
            }

            ++i;
        }

        return params;
    }

    virtual std::any visitFunArg(ZHLParser::FunArgContext* ctx) override {
        FunctionParam param;
        _currentParam = &param;

        FullNameV name = std::any_cast<FullNameV>(visit(ctx->fullName()));

        if (std::holds_alternative<Array>(name)) {
            Array& arr = std::get<Array>(name);
            param._name = arr._name;
            param._type._array = true;
            param._type._arraySize = arr._size;
        } else {
            param._name = std::get<std::string>(name);
        }

        param._type = std::any_cast<Type>(visit(ctx->type()));

        if (auto argParam = ctx->argParam()) {
            param._reg = std::any_cast<Registers>(visit(argParam));
        }

        _currentParam = nullptr;
        return param;
    }

    virtual std::any visitArgParam(ZHLParser::ArgParamContext* ctx) override {
        std::string name = ctx->Register()->toString();

        std::map<std::string, Registers> assoc;
        assoc["eax"] = Registers::EAX;
        assoc["ebx"] = Registers::EBX;
        assoc["ecx"] = Registers::ECX;
        assoc["edx"] = Registers::EDX;
        assoc["esi"] = Registers::ESI;
        assoc["edi"] = Registers::EDI;
        assoc["esp"] = Registers::ESP;
        assoc["ebp"] = Registers::EBP;
        assoc["xmm0"] = Registers::XMM0;
        assoc["xmm1"] = Registers::XMM1;
        assoc["xmm2"] = Registers::XMM2;
        assoc["xmm3"] = Registers::XMM3;
        assoc["xmm4"] = Registers::XMM4;
        assoc["xmm5"] = Registers::XMM5;
        assoc["xmm6"] = Registers::XMM6;
        assoc["xmm7"] = Registers::XMM7;

        return assoc[name];
    }

    virtual std::any visitOptNamedFunArgs(ZHLParser::OptNamedFunArgsContext* ctx) override {
        return 0;
    }

    virtual std::any visitOptNamedFunArg(ZHLParser::OptNamedFunArgContext* ctx) override {
        return 0;
    }

    virtual std::any visitTemplateSpec(ZHLParser::TemplateSpecContext* ctx) override {
        return 0;
    }

    virtual std::any visitType(ZHLParser::TypeContext* ctx) override {
        Type base = std::any_cast<Type>(visit(ctx->typeSpecifier()));
        // std::vector<PointerDecl> pointers;
        for (auto ptrCtx: ctx->pointerAttribute()) {
            base._pointerDecl.push_back(std::any_cast<PointerDecl>(visit(ptrCtx)));
        }
        return base;
    }

    virtual std::any visitTypeSpecifier(ZHLParser::TypeSpecifierContext* ctx) override {
        Type result;

        auto cstQual = ctx->Const();
        result._const = !cstQual.empty();

        if (cstQual.size() == 2) {
            _errors << ErrorLogger::warn << "const used multiple times " << GetContext() << ErrorLogger::_end;
        }

        if (auto simple = ctx->simpleType()) {
            result._name = std::any_cast<BasicType>(visit(simple));
        } else {
            std::string name = MergeNameParts(std::any_cast<std::vector<std::string>>(visit(ctx->nestedName())));
            Struct* target = GetStructByName(name);
            result._name = target;
        }

        return result;
    }

    virtual std::any visitSimpleType(ZHLParser::SimpleTypeContext* ctx) override {
        BasicType basic;

        if (ctx->Bool()) {
            basic._type = BasicTypes::BOOL;
        } else if (ctx->Void()) {
            basic._type = BasicTypes::VOID;
        } else if (ctx->Char()) {
            basic._type = BasicTypes::CHAR;
        } else if (ctx->Double()) {
            basic._type = BasicTypes::DOUBLE;
        } else if (ctx->Float()) {
            basic._type = BasicTypes::FLOAT;
        } else {
            basic._type = BasicTypes::INT;
        }

        if (auto sign = ctx->simpleTypeSignedness()) {
            if (basic._type != BasicTypes::CHAR && basic._type != BasicTypes::INT) {
                _errors << ErrorLogger::warn << "Cannot specify sign modifier (" << sign->getText() << ") on type " << BasicTypeToString(basic._type) << GetContext() << ErrorLogger::_end;
            } else {
                basic._sign = std::any_cast<Signedness>(visit(sign));
            }
        } else {
            basic._sign = Signedness::SIGNED;
        }

        auto length = ctx->simpleTypeLength();
        if (length.size()) {
            if (basic._type != BasicTypes::DOUBLE && basic._type != BasicTypes::INT) {
                _errors << ErrorLogger::warn << "Cannot specify length modifier on type " << BasicTypeToString(basic._type) << GetContext() << ErrorLogger::_end;
            } else {
                if (length.size() == 1) {
                    basic._length = std::any_cast<Length>(visit(length.front()));
                } else {
                    Length first = std::any_cast<Length>(visit(length[0]));
                    Length second = std::any_cast<Length>(visit(length[1]));

                    if (first != second) {
                        _errors << ErrorLogger::error << "Cannot specify short and long simultaneously on type " << BasicTypeToString(basic._type) << GetContext() << ErrorLogger::_end;
                    } else if (first == Length::SHORT) {
                        _errors << ErrorLogger::warn << "short specified multiple times on type " << BasicTypeToString(basic._type) << GetContext() << ErrorLogger::_end;
                        basic._length = first;
                    } else {
                        basic._length = Length::LONGLONG;
                    }
                }
            }
        }

        return basic;
    }

    virtual std::any visitSimpleTypeSignedness(ZHLParser::SimpleTypeSignednessContext* ctx) override {
        if (ctx->Signed()) {
            return Signedness::SIGNED;
        } else {
            return Signedness::UNSIGNED;
        }
    }

    virtual std::any visitSimpleTypeLength(ZHLParser::SimpleTypeLengthContext* ctx) override {
        if (ctx->Long()) {
            return Length::LONG;
        } else {
            return Length::SHORT;
        }
    }

    virtual std::any visitNestedName(ZHLParser::NestedNameContext* ctx) override {
        std::vector<antlr4::tree::TerminalNode*> parts = ctx->Name();
        std::vector<std::string> partsStr;
        for (auto x : parts)
            partsStr.push_back(x->toString());
        std::string type = partsStr[0];
        // std::cout << "Nested name " << type << std::endl;

        CheckOrRegStruct(type);

        return partsStr;
    }

    virtual std::any visitPointerAttribute(ZHLParser::PointerAttributeContext* ctx) override {
        PointerDecl decl;

        auto refs = ctx->CppRef();
        switch (refs.size()) {
        case 0:
            decl._kind = PointerKind::POINTER;
            break;

        case 1:
            decl._kind = PointerKind::LREF;
            break;

        case 2:
            decl._kind = PointerKind::RREF;
            break;

        default:
            throw std::runtime_error("Invalid pointer qualifier");
        }

        decl._const = ctx->Const() != nullptr;

        return decl;
    }

    virtual std::any visitGenericCode(ZHLParser::GenericCodeContext* ctx) override {
        return 0;
    }

    virtual std::any visitClass(ZHLParser::ClassContext* ctx) override {
        std::string name(ctx->Name()->getText());
        Struct* st = GetStructByName(name);
        st->_pending = false;

        if (auto deps = ctx->depends()) {
            st->_deps = std::any_cast<std::set<Struct*>>(visit(ctx->depends()));
        }
        _currentStruct = st;

        if (auto inheritance = ctx->inheritance()) {
            st->_parents = std::any_cast<std::set<std::pair<Struct*, Visibility>>>(visit(ctx->inheritance()));
        }

        visit(ctx->classBody());
    }

    virtual std::any visitDepends(ZHLParser::DependsContext* ctx) override {
        std::set<Struct*> deps;
        auto names = ctx->Name();

        for (int i = 0; i < names.size(); ++i) {
            std::string name(names[i]->getText());
            Struct* st = GetStructByName(name);
            if (deps.find(st) != deps.end()) {
                _errors << ErrorLogger::warn << "Specified " << name << " as dependency for " << _currentStruct->_name << " multiple times " << ErrorLogger::_end;
            } else if (st == _currentStruct) {
                _errors << ErrorLogger::warn << "Specified " << name << " as self dependency " << ErrorLogger::_end;
            } else {
                deps.insert(st);
            }
        }

        return deps;
    }

    virtual std::any visitClassBody(ZHLParser::ClassBodyContext* ctx) override {
        return 0;
    }

    virtual std::any visitClassSignature(ZHLParser::ClassSignatureContext* ctx) override {
        return 0;
    }

    virtual std::any visitClassFunction(ZHLParser::ClassFunctionContext* ctx) override {
        return 0;
    }

    virtual std::any visitClassField(ZHLParser::ClassFieldContext* ctx) override {
        return 0;
    }

    virtual std::any visitInnerField(ZHLParser::InnerFieldContext* ctx) override {
        return 0;
    }

    virtual std::any visitFullName(ZHLParser::FullNameContext* ctx) override {
        FullNameV result;
        std::string name(ctx->Name()->getText());
        if (ctx->RightRBracket()) {
            Array arr;
            arr._name = name;
            std::stringstream s;
            s << ctx->Number()->getText();
            s >> arr._size;
            result = arr;
        } else {
            result = name;
        }

        return result;
    }

    virtual std::any visitSignature(ZHLParser::SignatureContext* ctx) override {
        std::string fullSignature;
        SignatureV sig;

        if (auto sigCtx = ctx->Signature()) {
            Signature s;
            fullSignature = sigCtx->getText();
            s._sig = fullSignature.substr(1, fullSignature.size() - 3);
            s._function = std::any_cast<Function>(visit(ctx->function()));
            sig = s;

            //std::cout << "Read function signature " << s._sig << " for " << s._function.ToString() << std::endl; // GetCurrentFunctionQualifiedName(s._function._name) << std::endl;
        } else {
            VariableSignature s;
            fullSignature = ctx->ReferenceSignature()->getText();
            s._sig = fullSignature.substr(1, fullSignature.size() - 3);
            s._variable = std::any_cast<Variable>(visit(ctx->reference()));

            //std::cout << "Read reference signature " << s._sig << " for variable " << s._variable._name << std::endl;
        }

        return sig;
    }

    virtual std::any visitForwardDecl(ZHLParser::ForwardDeclContext* ctx) override {
        return 0;
    }

    virtual std::any visitTypedef(ZHLParser::TypedefContext* ctx) override {
        return 0;
    }

    virtual std::any visitFunctionPtr(ZHLParser::FunctionPtrContext* ctx) override {
        return 0;
    }

    virtual std::any visitFptr(ZHLParser::FptrContext* ctx) override {
        return 0;
    }

    virtual std::any visitMemberPtr(ZHLParser::MemberPtrContext* ctx) override {
        return 0;
    }

    virtual std::any visitInheritance(ZHLParser::InheritanceContext* ctx) override {
        return 0;
    }

    virtual std::any visitInheritanceDecl(ZHLParser::InheritanceDeclContext *ctx) override {
        Visibility vis;
        if (auto visibility = ctx->Visibility()) {
            std::string visStr(visibility->getText());
            if (visStr == "public") {
                vis = Visibility::PUBLIC;
            } else if (visStr == "private") {
                vis = Visibility::PRIVATE;
            } else {
                vis = Visibility::PROTECTED;
            }
        }
        return std::pair<std::vector<std::string>, std::optional<Visibility>>(std::any_cast<std::vector<std::string>>(visit(ctx->nestedName())), ctx->Visibility() ? std::optional<Visibility>(vis) : std::nullopt);
    }

private:
    Namespace* _global;
    // std::vector<Struct*> _structs;
    std::string _currentFile;
    Struct* _currentStruct = nullptr;
    Variable* _currentVariable = nullptr;
    Function* _currentFunction = nullptr;
    FunctionParam* _currentParam = nullptr;
    Signature* _currentSignature = nullptr;
    VariableSignature* _currentReference = nullptr;

    ErrorLogger _errors;
    std::map<std::string, Struct*>* _types;

    std::string GetCurrentFunctionQualifiedName(std::string const& name) {
        if (!_currentStruct) {
            return name;
        } else {
            return _currentStruct->_name + "::" + name;
        }
    }

    void WarnRepeatedFunctionQualifier(std::string const& name, std::string const& qualifier) {
        _errors << ErrorLogger::warn << "Repeated '" << qualifier << "' qualifier on function " << name << ErrorLogger::endl << ErrorLogger::_end;
    }

    std::string MergeNameParts(std::vector<std::string> const& parts) {
        std::ostringstream s;
        for (int i = 0; i < parts.size(); ++i) {
            s << parts[i];
            if (i != parts.size() - 1) {
                s << "::";
            }
        }
        return s.str();
    }

    std::string GetContext() {
        std::ostringstream context;
        if (_currentParam) {
            context << " in parameter " << _currentParam->_name << " ";
            if (_currentFunction) {
                context << " in function " << _currentFunction->_name << " ";
                if (_currentStruct) {
                    context << " in structure " << _currentStruct->_name << " ";
                }
            }
        } else if (_currentVariable) {
            context << " in variable " << _currentVariable->_name << " ";
            if (_currentStruct) {
                context << " in structure " << _currentStruct->_name << " ";
            }
        } else if (_currentFunction) {
            context << " in function " << _currentFunction->_name << " ";
            if (_currentStruct) {
                context << " in structure " << _currentStruct->_name << " ";
            }
        } else if (_currentStruct) {
            context << " in structure " << _currentStruct->_name << " ";
        }

        return context.str();
    }

    Struct* GetStructByName(std::string const& name) {
        Struct* st;
        if (auto iter = _types->find(name); iter != _types->end()) {
            st = iter->second;
        } else {
            st = new Struct;
            st->_name = name;
            (*_types)[name] = st;
        }

        return st;
    }

    void CheckOrRegStruct(std::string const& name) {
        if (_types->find(name) == _types->end()) {
            Struct* st = new Struct;
            st->_name = name;
            (*_types)[name] = st;
        }
    }
};

void process_file(std::map<std::string, Struct*>* types, fs::path const& path) {
    //std::cout << "Processing " << path << std::endl;
    std::ifstream stream(path);

    if (!stream.is_open()) {
        return;
    }

    //std::cout << "Visiting " << path << std::endl;
    antlr4::ANTLRInputStream input_stream(stream);
    ZHLLexer lexer(&input_stream);
    antlr4::CommonTokenStream tokens(&lexer);
    ZHLParser parser(&tokens);

    antlr4::tree::ParseTree* tree = parser.zhl();
    Parser p2(types);
    p2.visit(tree);
}

int main(int argc, char** argv) {
    fs::path functions; // ("../../libzhl/functions");
    if (argc != 1) {
        functions = fs::path(argv[1]);
    } else {
        functions = "../../libzhl/functions";
    }

    std::map<std::string, Struct*> types;
	for (fs::directory_entry const& entry : fs::directory_iterator(functions)) {
		//std::cout << "File " << entry.path() << std::endl;
		if (!entry.is_regular_file())
			continue;

		//std::cout << "Ext " << entry.path().extension() << std::endl;
		if (entry.path().extension() != std::string(".zhl"))
			continue;

        process_file(&types, entry.path());
	}

    process_file(&types, "../../libzhlgen/IsaacRepentanceStripped.h");

    void (Parser::*foo)(int);

	return 0;
}