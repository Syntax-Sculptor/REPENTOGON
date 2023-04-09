# Class "Color"
 
## Functions

### Get·Colorize () {: aria-label='Functions' }
#### table GetColorize ( ) {: .copyable aria-label='Functions' }
Returns a table corresponding to the color's current Colorize values: `{R, G, B, A}`

___
### Get·Offset () {: aria-label='Functions' }
#### table GetOffset ( ) {: .copyable aria-label='Functions' }
Returns a table corresponding to the color's current Offset values: `{R, G, B}`

While the [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) class does already contain [.RO](https://wofsauge.github.io/IsaacDocs/rep/Color.html#ro), [.GO](https://wofsauge.github.io/IsaacDocs/rep/Color.html#go) and [.BO](https://wofsauge.github.io/IsaacDocs/rep/Color.html#bo) variables for this, GetOffset() has been measured to be ~30% faster in cases where access to all three values is necessary and is recommended in that scenario as a result. Performance is near identical when accessing two variables, and worse when accessing one. In cases where only one or two offset values are needed, stick with the variables.

___
### Get·Tint () {: aria-label='Functions' }
#### table GetTint ( ) {: .copyable aria-label='Functions' }
Returns a table corresponding to the color's current Tint values: `{R, G, B, A}`

___

## Constants

### Color.EmberFade {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) EmberFade {: .copyable aria-label='Constants' }
Used for enemies like Crackles and Coal Spiders. Gibs start orange and fade into grey.

Tint of (0, 0, 0, 1.1)
Colorize of (0, 0, 0, 0)
Offset of (1, 0.514, 0.004)

___
### Color.LaserAlmond {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserAlmond {: .copyable aria-label='Constants' }
Used for lasers with the Almond Milk effect.

___
### Color.LaserChocolate {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserChocolate {: .copyable aria-label='Constants' }
Used for lasers with the Chocolate Milk effect.

___
### Color.LaserCoal {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserCoal {: .copyable aria-label='Constants' }
Used for lasers with the A Lump of Coal effect.

___
### Color.LaserFireMind {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserFireMind {: .copyable aria-label='Constants' }
Used for lasers fired by players with Fire Mind.

___
### Color.LaserHoming {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserHoming {: .copyable aria-label='Constants' }
Used for homing lasers.

___
### Color.LaserIpecac {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserIpecac {: .copyable aria-label='Constants' }
Used for lasers with the Ipecac effect.

___
### Color.LaserMother {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserMother {: .copyable aria-label='Constants' }
Used for Mother's mega laser.

___
### Color.LaserNumberOne {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserNumberOne {: .copyable aria-label='Constants' }
Used for lasers fired by players with Number One.

___
### Color.LaserSoy {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserSoy {: .copyable aria-label='Constants' }
Used for lasers with the Soy Milk effect.

___
### Color.LaserPoison {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) LaserPoison {: .copyable aria-label='Constants' }
Used for poisonous lasers fired by players with items like Scorpio or Common Cold.

___
### Color.ProjectileCageBlue {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCageBlue {: .copyable aria-label='Constants' }
Used for `ProjectileVariant.PROJECTILE_PUKE`s fired by The Cage.

___
### Color.ProjectileCorpseClusterDark {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCorpseClusterDark {: .copyable aria-label='Constants' }
Used for clustered `ProjectileVariant.PROJECTILE_NORMAL`s fired in Corpse by enemies like Mother.

___
### Color.ProjectileCorpseClusterLight {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCorpseClusterLight {: .copyable aria-label='Constants' }
Used for clustered `ProjectileVariant.PROJECTILE_NORMAL`s fired in Corpse by enemies like Mother.

___
### Color.ProjectileCorpseGreen {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCorpseGreen {: .copyable aria-label='Constants' }
Used for green `ProjectileVariant.PROJECTILE_NORMAL`s fired in Corpse by enemies like Mother.

Also used for the green laser fired by Chimera.

___
### Color.ProjectileCorpsePink {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCorpsePink {: .copyable aria-label='Constants' }
Used for pink-ish white-ish `ProjectileVariant.PROJECTILE_NORMAL`s fired in Corpse by enemies like Mother.

___
### Color.ProjectileCorpseWhite {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCorpseWhite {: .copyable aria-label='Constants' }
Used for white-ish grey-ish `ProjectileVariant.PROJECTILE_NORMAL`s fired in Corpse by enemies like Mother.

___
### Color.ProjectileCorpseYellow {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileCorpseYellow {: .copyable aria-label='Constants' }
Used for yellow `ProjectileVariant.PROJECTILE_NORMAL`s fired in Corpse by enemies like The Scourge.

___
### Color.ProjectileFireWave {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileFireWave {: .copyable aria-label='Constants' }
Used for fire-pillar-wave-spawning `ProjectileVariant.PROJECTILE_NORMAL`s fired by enemies like Crackle.

___
### Color.ProjectileHoming {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileHoming {: .copyable aria-label='Constants' }
Used for homing `ProjectileVariant.PROJECTILE_NORMAL`s fired by enemies like Psychic Maw.

___
### Color.ProjectileHushBlue {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileHushBlue {: .copyable aria-label='Constants' }
Used for blue `ProjectileVariant.PROJECTILE_HUSH`s fired by Hush.

___
### Color.ProjectileHushGreen {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileHushGreen {: .copyable aria-label='Constants' }
Used for blue `ProjectileVariant.PROJECTILE_HUSH`s fired by Hush.

___
### Color.ProjectileHushYellow {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileHushYellow {: .copyable aria-label='Constants' }
Used for blue `ProjectileVariant.PROJECTILE_HUSH`s fired by Hush.

___
### Color.ProjectileIpecac {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileIpecac {: .copyable aria-label='Constants' }
Used for explosive `ProjectileVariant.PROJECTILE_NORMAL`s fired by enemies like Gurgles.

___
### Color.ProjectileMegaSatanBlack {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileMegaSatanBlack {: .copyable aria-label='Constants' }
Used for black `ProjectileVariant.PROJECTILE_NORMAL`s fired by Mega Satan.

___
### Color.ProjectileMegaSatanWhite {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileMegaSatanWhite {: .copyable aria-label='Constants' }
Used for white `ProjectileVariant.PROJECTILE_NORMAL`s fired by Mega Satan.

___
### Color.ProjectileSoy {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileSoy {: .copyable aria-label='Constants' }
Used for soy `ProjectileVariant.PROJECTILE_NORMAL`s fired by enemies like Soy Creep.

___
### Color.ProjectileTar {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) ProjectileTar {: .copyable aria-label='Constants' }
Used for tar `ProjectileVariant.PROJECTILE_NORMAL`s fired by enemies like Clot.

___
### Color.TearAlmond {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearAlmond {: .copyable aria-label='Constants' }
Used for tears fired by players with Soy Milk.

___
### Color.TearChocolate {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearChocolate {: .copyable aria-label='Constants' }
Used for tears fired by players with Chocolate Milk.

___
### Color.TearCoal {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearCoal {: .copyable aria-label='Constants' }
Used for tears fired by players with A Lump of Coal.

___
### Color.TearCommonCold {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearCommonCold {: .copyable aria-label='Constants' }
Used for poison tears fired by players with Common Cold.

___
### Color.TearHoming {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearHoming {: .copyable aria-label='Constants' }
Used for homing tears fired by players with Spoon Bender.

___
### Color.TearIpecac {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearIpecac {: .copyable aria-label='Constants' }
Used for explosive tears fired by players with Ipecac.

___
### Color.TearNumberOne {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearNumberOne {: .copyable aria-label='Constants' }
Used for tears fired by players with Number One.

___
### Color.TearScorpio {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearScorpio {: .copyable aria-label='Constants' }
Used for poison tears fired by players with Scorpio.

___
### Color.TearSerpentsKiss {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearSerpentsKiss {: .copyable aria-label='Constants' }
Used for poison tears fired by players with Serpent's Kiss.

___
### Color.TearSoy {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearSoy {: .copyable aria-label='Constants' }
Used for tears fired by players with Soy Milk.

___
### Color.TearTar {: aria-label='Constants' }
[ ](#){: .rep .tooltip .badge }
#### [Color](https://wofsauge.github.io/IsaacDocs/rep/Color.html) TearTar {: .copyable aria-label='Constants' }
Used for tar tears fired by familiars like Little Gish.

___