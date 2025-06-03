# XGecuPatcher
Patch for the XGecu Software Xgpro v12.90 to use custom adapters


# Usage
You can apply the patch in one of two ways:

# Option 1: Inject into the running process
> Inject the DLL directly into the Xgpro process using your preferred DLL injection method.

# Option 2: Use the Serialnumber directory
> Place the DLL file in the \Serialnumber directory inside the Xgpro installation folder.
> 
> Open Xgpro and go to the menu Device (D) → Serials Number.
> 
> Check the User Define option.
> 
> Under Algorithm, select your custom DLL from the dropdown list.

Using this project, you can also view the adapter pinout by selecting a chip for the desired adapter and then clicking "Read".
This will trigger the Pin Detect error, which reveals all the necessary pin connections for the chip.
However, it does not display the resistors and capacitors required for stabilization and filtering.
In my case, this led to inconsistent readings. 




Credits
GUI credits: https://github.com/noahware/external-overlay
