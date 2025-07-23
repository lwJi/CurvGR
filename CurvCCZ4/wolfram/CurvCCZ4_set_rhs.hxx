/* CurvCCZ4_set_rhs.hxx */
/* Produced with Generato */

#ifndef CURVCCZ4_SET_RHS_HXX
#define CURVCCZ4_SET_RHS_HXX

const auto dtphi = gf_dtphi;
const auto dttrK = gf_dttrK;
const auto dtTheta = gf_dtTheta;
const auto dtalpha = gf_dtalpha;
const auto dtepsOsph11 = gf_dteps[0];
const auto dtepsOsph12 = gf_dteps[1];
const auto dtepsOsph13 = gf_dteps[2];
const auto dtepsOsph22 = gf_dteps[3];
const auto dtepsOsph23 = gf_dteps[4];
const auto dtepsOsph33 = gf_dteps[5];
const auto dtexAbOsph11 = gf_dtexAb[0];
const auto dtexAbOsph12 = gf_dtexAb[1];
const auto dtexAbOsph13 = gf_dtexAb[2];
const auto dtexAbOsph22 = gf_dtexAb[3];
const auto dtexAbOsph23 = gf_dtexAb[4];
const auto dtexAbOsph33 = gf_dtexAb[5];
const auto dtLtOsph1 = gf_dtLt[0];
const auto dtLtOsph2 = gf_dtLt[1];
const auto dtLtOsph3 = gf_dtLt[2];
const auto dtbetaOsph1 = gf_dtbeta[0];
const auto dtbetaOsph2 = gf_dtbeta[1];
const auto dtbetaOsph3 = gf_dtbeta[2];
const auto dtBOsph1 = gf_dtB[0];
const auto dtBOsph2 = gf_dtB[1];
const auto dtBOsph3 = gf_dtB[2];

const auto phi = gf_phi;
const auto trK = gf_trK;
const auto Theta = gf_Theta;
const auto alpha = gf_alpha;
const auto epsOsph11 = gf_eps[0];
const auto epsOsph12 = gf_eps[1];
const auto epsOsph13 = gf_eps[2];
const auto epsOsph22 = gf_eps[3];
const auto epsOsph23 = gf_eps[4];
const auto epsOsph33 = gf_eps[5];
const auto exAbOsph11 = gf_exAb[0];
const auto exAbOsph12 = gf_exAb[1];
const auto exAbOsph13 = gf_exAb[2];
const auto exAbOsph22 = gf_exAb[3];
const auto exAbOsph23 = gf_exAb[4];
const auto exAbOsph33 = gf_exAb[5];
const auto LtOsph1 = gf_Lt[0];
const auto LtOsph2 = gf_Lt[1];
const auto LtOsph3 = gf_Lt[2];
const auto betaOsph1 = gf_beta[0];
const auto betaOsph2 = gf_beta[1];
const auto betaOsph3 = gf_beta[2];
const auto BOsph1 = gf_B[0];
const auto BOsph2 = gf_B[1];
const auto BOsph3 = gf_B[2];

noinline([&]() __attribute__((__flatten__, __hot__)) {
grid.loop_int_device<0, 0, 0>(
  grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {
const int ijk = layout2.linear(p.i, p.j, p.k);

const auto R = p.x;
const auto T = p.y;
const auto P = p.z;

const auto
eps11[ijk]
=
epsOsph11[ijk]
;

const auto
eps12[ijk]
=
R*epsOsph12[ijk]
;

const auto
eps13[ijk]
=
R*epsOsph13[ijk]*Sin(T)
;

const auto
eps22[ijk]
=
Power(R,2)*epsOsph22[ijk]
;

const auto
eps23[ijk]
=
Power(R,2)*epsOsph23[ijk]*Sin(T)
;

const auto
eps33[ijk]
=
Power(R,2)*epsOsph33[ijk]*Power(Sin(T),2)
;

const auto
exAb11[ijk]
=
exAbOsph11[ijk]
;

const auto
exAb12[ijk]
=
R*exAbOsph12[ijk]
;

const auto
exAb13[ijk]
=
R*exAbOsph13[ijk]*Sin(T)
;

const auto
exAb22[ijk]
=
Power(R,2)*exAbOsph22[ijk]
;

const auto
exAb23[ijk]
=
Power(R,2)*exAbOsph23[ijk]*Sin(T)
;

const auto
exAb33[ijk]
=
Power(R,2)*exAbOsph33[ijk]*Power(Sin(T),2)
;

const auto
Lt1[ijk]
=
LtOsph1[ijk]
;

const auto
Lt2[ijk]
=
LtOsph2[ijk]/R
;

const auto
Lt3[ijk]
=
(Csc(T)*LtOsph3[ijk])/R
;

const auto
beta1[ijk]
=
betaOsph1[ijk]
;

const auto
beta2[ijk]
=
betaOsph2[ijk]/R
;

const auto
beta3[ijk]
=
(Csc(T)*betaOsph3[ijk])/R
;

const auto
B1[ijk]
=
BOsph1[ijk]
;

const auto
B2[ijk]
=
BOsph2[ijk]/R
;

const auto
B3[ijk]
=
(Csc(T)*BOsph3[ijk])/R
;


const auto
deps111
=
depsOsph111
;

const auto
deps112
=
depsOsph112*R + epsOsph12[ijk]
;

const auto
deps113
=
(depsOsph113*R + epsOsph13[ijk])*Sin(T)
;

const auto
deps122
=
R*(depsOsph122*R + 2*epsOsph22[ijk])
;

const auto
deps123
=
R*(depsOsph123*R + 2*epsOsph23[ijk])*Sin(T)
;

const auto
deps133
=
R*(depsOsph133*R + 2*epsOsph33[ijk])*Power(Sin(T),2)
;

const auto
deps211
=
depsOsph211
;

const auto
deps212
=
depsOsph212*R
;

const auto
deps213
=
R*(Cos(T)*epsOsph13[ijk] + depsOsph213*Sin(T))
;

const auto
deps222
=
depsOsph222*Power(R,2)
;

const auto
deps223
=
Power(R,2)*(Cos(T)*epsOsph23[ijk] + depsOsph223*Sin(T))
;

const auto
deps233
=
Power(R,2)*Sin(T)*(2*Cos(T)*epsOsph33[ijk] + depsOsph233*Sin(T))
;

const auto
deps311
=
depsOsph311
;

const auto
deps312
=
depsOsph312*R
;

const auto
deps313
=
depsOsph313*R*Sin(T)
;

const auto
deps322
=
depsOsph322*Power(R,2)
;

const auto
deps323
=
depsOsph323*Power(R,2)*Sin(T)
;

const auto
deps333
=
depsOsph333*Power(R,2)*Power(Sin(T),2)
;

const auto
dexAb111
=
dexAbOsph111
;

const auto
dexAb112
=
dexAbOsph112*R + exAbOsph12[ijk]
;

const auto
dexAb113
=
(dexAbOsph113*R + exAbOsph13[ijk])*Sin(T)
;

const auto
dexAb122
=
R*(dexAbOsph122*R + 2*exAbOsph22[ijk])
;

const auto
dexAb123
=
R*(dexAbOsph123*R + 2*exAbOsph23[ijk])*Sin(T)
;

const auto
dexAb133
=
R*(dexAbOsph133*R + 2*exAbOsph33[ijk])*Power(Sin(T),2)
;

const auto
dexAb211
=
dexAbOsph211
;

const auto
dexAb212
=
dexAbOsph212*R
;

const auto
dexAb213
=
R*(Cos(T)*exAbOsph13[ijk] + dexAbOsph213*Sin(T))
;

const auto
dexAb222
=
dexAbOsph222*Power(R,2)
;

const auto
dexAb223
=
Power(R,2)*(Cos(T)*exAbOsph23[ijk] + dexAbOsph223*Sin(T))
;

const auto
dexAb233
=
Power(R,2)*Sin(T)*(2*Cos(T)*exAbOsph33[ijk] + dexAbOsph233*Sin(T))
;

const auto
dexAb311
=
dexAbOsph311
;

const auto
dexAb312
=
dexAbOsph312*R
;

const auto
dexAb313
=
dexAbOsph313*R*Sin(T)
;

const auto
dexAb322
=
dexAbOsph322*Power(R,2)
;

const auto
dexAb323
=
dexAbOsph323*Power(R,2)*Sin(T)
;

const auto
dexAb333
=
dexAbOsph333*Power(R,2)*Power(Sin(T),2)
;

const auto
dLt11
=
dLtOsph11
;

const auto
dLt12
=
(dLtOsph12*R - LtOsph2[ijk])/Power(R,2)
;

const auto
dLt13
=
(Csc(T)*(dLtOsph13*R - LtOsph3[ijk]))/Power(R,2)
;

const auto
dLt21
=
dLtOsph21
;

const auto
dLt22
=
dLtOsph22/R
;

const auto
dLt23
=
(Csc(T)*(dLtOsph23 - Cot(T)*LtOsph3[ijk]))/R
;

const auto
dLt31
=
dLtOsph31
;

const auto
dLt32
=
dLtOsph32/R
;

const auto
dLt33
=
(dLtOsph33*Csc(T))/R
;

const auto
dbeta11
=
dbetaOsph11
;

const auto
dbeta12
=
(dbetaOsph12*R - betaOsph2[ijk])/Power(R,2)
;

const auto
dbeta13
=
(Csc(T)*(dbetaOsph13*R - betaOsph3[ijk]))/Power(R,2)
;

const auto
dbeta21
=
dbetaOsph21
;

const auto
dbeta22
=
dbetaOsph22/R
;

const auto
dbeta23
=
(Csc(T)*(dbetaOsph23 - Cot(T)*betaOsph3[ijk]))/R
;

const auto
dbeta31
=
dbetaOsph31
;

const auto
dbeta32
=
dbetaOsph32/R
;

const auto
dbeta33
=
(dbetaOsph33*Csc(T))/R
;

const auto
dB11
=
dBOsph11
;

const auto
dB12
=
(dBOsph12*R - BOsph2[ijk])/Power(R,2)
;

const auto
dB13
=
(Csc(T)*(dBOsph13*R - BOsph3[ijk]))/Power(R,2)
;

const auto
dB21
=
dBOsph21
;

const auto
dB22
=
dBOsph22/R
;

const auto
dB23
=
(Csc(T)*(dBOsph23 - Cot(T)*BOsph3[ijk]))/R
;

const auto
dB31
=
dBOsph31
;

const auto
dB32
=
dBOsph32/R
;

const auto
dB33
=
(dBOsph33*Csc(T))/R
;


  });
});

#endif // #ifndef CURVCCZ4_SET_RHS_HXX

/* CurvCCZ4_set_rhs.hxx */
