# SBDataTable
Steller Blade DataTable Definitions and Importer.

### about this
This repository manages Stellar Blade's data.  It defines the structure of the DataTables found in the `/Game/Local/Data` folder's `.json` files, reads data from these JSON files, and imports them as DataTables into the UE4 Editor.  
All DataTables in this folder share the same structure; the code defines a structure for each 'Rows' element within each `.json` file.  

Checking out the repository into your project's `uproject/Source` folder creates an `SB` folder.

## Attention!!
You may encounter packing issues when compiling and running.  If so, you'll need to disable Smart App Control.  Only use this if you've already disabled it or have the ability to.
