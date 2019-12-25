// Extrapolate p, U and phi
p = (2*p.oldTime() - p.oldTime().oldTime());
p.correctBoundaryConditions();

U = (2*U.oldTime() - U.oldTime().oldTime());
U.correctBoundaryConditions();

phi = (2*phi.oldTime() - phi.oldTime().oldTime());


// Solve the Momentum equation

MRF.correctBoundaryVelocity(U);

fvVectorMatrix UEqn
(
    fvm::ddt(U) + fvm::div(phi, U)
  + MRF.DDt(U)
  + turbulence->divDevReff(U)
 ==
    fvOptions(U)
);

UEqn.relax();

fvOptions.constrain(UEqn);

if (piso.momentumPredictor())
{
    solve(UEqn == -fvc::grad(p));

    fvOptions.correct(U);
}
