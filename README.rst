.. -*- fill-column: 120; -*-

Studying the DM368 EVM code from TI
===================================

I want to do some interaction with video data on the DM368 EVM board. The software in TI's SDK makes it a little
non-obvious how to go about this because they have layers and layers of indirection, and a pointer to an actual
buffer is buried away in some obscure C header file among thousands, as if accessing video data is something that
nobody has ever wanted to do. Go figure.
