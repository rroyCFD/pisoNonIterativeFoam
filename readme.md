## Application : Non-iterative version of pisoFoam (pisoNonIterativeFoam)

### Author:
- Rajib Roy
- University of Wyoming
- rroy@uwyo.edu, roy.rajib@live.com

### Description
Transient solver for incompressible, turbulent flow, using the PISO algorithm.

At each time-step (n+1), the variables (velocity, face flux and pressure) are extrapolated to have a better than 1st order estimation. This enables applying only one poison pressure correction loop. This method has potential to be efficient in an unsteady simulations where mean CFL number is low. Multiple pressure correction iteration may be performed if required. The insignificant computational cost of field extrapolation is compensated by better estimation for the linear system solvers.

Using non-iterative from proposed by

    Tuković, Ž., Perić, M., & Jasak, H. (2018).
    Consistent second-order time-accurate non-iterative PISO-algorithm.
    Computers & ,166,78–85https://doi.org/10.1016/j.compfluid.2018.01.041

Sub-models include:

    * turbulence modelling, i.e. laminar, RAS or LES
    * run-time selectable MRF and finite volume options, e.g. explicit porosity

Future improvement ideas:

    * Extrapolate trubulence parameters (e.g. k, epsilon, omega, etc.) for explicit terms in the linear system for faster convergence, and better accuracy.



### Disclaiimer:

This application is built based on [OpenFOAM version-6](https://openfoam.org/release/6/). Please read the _About OpenFOAM_ section to learn more on OpenFOAM.

The application is free to use. The author neither provide any warranty nor shall be liable for any damage incurred from this application.



#### About OpenFOAM

OpenFOAM is the leading free, open source software for computational fluid dynamics (CFD), owned by the OpenFOAM Foundation and distributed exclusively under the [General Public Licence (GPL)](http://www.gnu.org/copyleft/gpl.html). The GPL gives users the freedom to modify and redistribute the software and a guarantee of continued free use, within the terms of the licence. To learn more visit [https://openfoam.org/](https://openfoam.org/)

