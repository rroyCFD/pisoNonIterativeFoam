// Extrapolate U and phi
phi = (2*phi.oldTime() - phi.oldTime().oldTime());

U = (2*U.oldTime() - U.oldTime().oldTime());
U.correctBoundaryConditions();

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


// Extrapolate p
p = (2*p.oldTime() - p.oldTime().oldTime());
p.correctBoundaryConditions();


if (piso.momentumPredictor())
{
    solve(UEqn == -fvc::grad(p));

    fvOptions.correct(U);
}
