## Overal
Library advertises 4 characteristics in order to indicate software/hardware type/version.
See `ADVERTISING.md`. User of library can decide what characteristics should contain.\
Central can handle this data and check if software should be updated.

## Example
We have peripheral device with information:
```
hardware name: MyHardware
hardware ver: 1.0.0
software name: MySoftware
software ver: 1.0.0
```
Central found new software where:
```
software name: MySoftware
software ver: 2.0.0
for hardware name: MyHardware
for hardware ver: 1.0.0
```
As we see:
- hardware names and versions are mathed
- software version in central side is higher

We can update our peripheral device to software version `2.0.0`.
