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
sinth*(depsOsph113*R + epsOsph13[ijk])
;

const auto
deps122
=
R*(depsOsph122*R + 2*epsOsph22[ijk])
;

const auto
deps123
=
R*sinth*(depsOsph123*R + 2*epsOsph23[ijk])
;

const auto
deps133
=
R*Power(sinth,2)*(depsOsph133*R + 2*epsOsph33[ijk])
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
R*(depsOsph213*sinth + costh*epsOsph13[ijk])
;

const auto
deps222
=
depsOsph222*Power(R,2)
;

const auto
deps223
=
Power(R,2)*(depsOsph223*sinth + costh*epsOsph23[ijk])
;

const auto
deps233
=
Power(R,2)*sinth*(depsOsph233*sinth + 2*costh*epsOsph33[ijk])
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
depsOsph313*R*sinth
;

const auto
deps322
=
depsOsph322*Power(R,2)
;

const auto
deps323
=
depsOsph323*Power(R,2)*sinth
;

const auto
deps333
=
depsOsph333*Power(R,2)*Power(sinth,2)
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
sinth*(dexAbOsph113*R + exAbOsph13[ijk])
;

const auto
dexAb122
=
R*(dexAbOsph122*R + 2*exAbOsph22[ijk])
;

const auto
dexAb123
=
R*sinth*(dexAbOsph123*R + 2*exAbOsph23[ijk])
;

const auto
dexAb133
=
R*Power(sinth,2)*(dexAbOsph133*R + 2*exAbOsph33[ijk])
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
R*(dexAbOsph213*sinth + costh*exAbOsph13[ijk])
;

const auto
dexAb222
=
dexAbOsph222*Power(R,2)
;

const auto
dexAb223
=
Power(R,2)*(dexAbOsph223*sinth + costh*exAbOsph23[ijk])
;

const auto
dexAb233
=
Power(R,2)*sinth*(dexAbOsph233*sinth + 2*costh*exAbOsph33[ijk])
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
dexAbOsph313*R*sinth
;

const auto
dexAb322
=
dexAbOsph322*Power(R,2)
;

const auto
dexAb323
=
dexAbOsph323*Power(R,2)*sinth
;

const auto
dexAb333
=
dexAbOsph333*Power(R,2)*Power(sinth,2)
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
(cscth*(dLtOsph13*R - LtOsph3[ijk]))/Power(R,2)
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
(cscth*(dLtOsph23 - cotth*LtOsph3[ijk]))/R
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
(cscth*dLtOsph33)/R
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
(cscth*(dbetaOsph13*R - betaOsph3[ijk]))/Power(R,2)
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
(cscth*(dbetaOsph23 - cotth*betaOsph3[ijk]))/R
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
(cscth*dbetaOsph33)/R
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
(cscth*(dBOsph13*R - BOsph3[ijk]))/Power(R,2)
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
(cscth*(dBOsph23 - cotth*BOsph3[ijk]))/R
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
(cscth*dBOsph33)/R
;


const auto
ddeps1111
=
ddepsOsph1111
;

const auto
ddeps1112
=
2*depsOsph112 + ddepsOsph1112*R
;

const auto
ddeps1113
=
(2*depsOsph113 + ddepsOsph1113*R)*sinth
;

const auto
ddeps1122
=
R*(4*depsOsph122 + ddepsOsph1122*R) + 2*epsOsph22[ijk]
;

const auto
ddeps1123
=
sinth*(R*(4*depsOsph123 + ddepsOsph1123*R) + 2*epsOsph23[ijk])
;

const auto
ddeps1133
=
Power(sinth,2)*(R*(4*depsOsph133 + ddepsOsph1133*R) + 2*epsOsph33[ijk])
;

const auto
ddeps1211
=
ddepsOsph1211
;

const auto
ddeps1212
=
depsOsph212 + ddepsOsph1212*R
;

const auto
ddeps1213
=
costh*depsOsph113*R + (depsOsph213 + ddepsOsph1213*R)*sinth +
  costh*epsOsph13[ijk]
;

const auto
ddeps1222
=
R*(2*depsOsph222 + ddepsOsph1222*R)
;

const auto
ddeps1223
=
R*(costh*depsOsph123*R + 2*depsOsph223*sinth + ddepsOsph1223*R*sinth +
    2*costh*epsOsph23[ijk])
;

const auto
ddeps1233
=
R*sinth*(2*costh*depsOsph133*R + 2*depsOsph233*sinth +
    ddepsOsph1233*R*sinth + 4*costh*epsOsph33[ijk])
;

const auto
ddeps1311
=
ddepsOsph1311
;

const auto
ddeps1312
=
depsOsph312 + ddepsOsph1312*R
;

const auto
ddeps1313
=
(depsOsph313 + ddepsOsph1313*R)*sinth
;

const auto
ddeps1322
=
R*(2*depsOsph322 + ddepsOsph1322*R)
;

const auto
ddeps1323
=
R*(2*depsOsph323 + ddepsOsph1323*R)*sinth
;

const auto
ddeps1333
=
R*(2*depsOsph333 + ddepsOsph1333*R)*Power(sinth,2)
;

const auto
ddeps2211
=
ddepsOsph2211
;

const auto
ddeps2212
=
ddepsOsph2212*R
;

const auto
ddeps2213
=
R*(2*costh*depsOsph213 + ddepsOsph2213*sinth - sinth*epsOsph13[ijk])
;

const auto
ddeps2222
=
ddepsOsph2222*Power(R,2)
;

const auto
ddeps2223
=
Power(R,2)*(2*costh*depsOsph223 + ddepsOsph2223*sinth - sinth*epsOsph23[ijk])
;

const auto
ddeps2233
=
Power(R,2)*(sinth*(4*costh*depsOsph233 + ddepsOsph2233*sinth) +
    2*(Power(costh,2) - Power(sinth,2))*epsOsph33[ijk])
;

const auto
ddeps2311
=
ddepsOsph2311
;

const auto
ddeps2312
=
ddepsOsph2312*R
;

const auto
ddeps2313
=
R*(costh*depsOsph313 + ddepsOsph2313*sinth)
;

const auto
ddeps2322
=
ddepsOsph2322*Power(R,2)
;

const auto
ddeps2323
=
Power(R,2)*(costh*depsOsph323 + ddepsOsph2323*sinth)
;

const auto
ddeps2333
=
Power(R,2)*sinth*(2*costh*depsOsph333 + ddepsOsph2333*sinth)
;

const auto
ddeps3311
=
ddepsOsph3311
;

const auto
ddeps3312
=
ddepsOsph3312*R
;

const auto
ddeps3313
=
ddepsOsph3313*R*sinth
;

const auto
ddeps3322
=
ddepsOsph3322*Power(R,2)
;

const auto
ddeps3323
=
ddepsOsph3323*Power(R,2)*sinth
;

const auto
ddeps3333
=
ddepsOsph3333*Power(R,2)*Power(sinth,2)
;

const auto
ddbeta111
=
ddbetaOsph111
;

const auto
ddbeta112
=
(R*(-2*dbetaOsph12 + ddbetaOsph112*R) + 2*betaOsph2[ijk])/Power(R,3)
;

const auto
ddbeta113
=
(cscth*(R*(-2*dbetaOsph13 + ddbetaOsph113*R) + 2*betaOsph3[ijk]))/Power(R,3)
;

const auto
ddbeta121
=
ddbetaOsph121
;

const auto
ddbeta122
=
(-dbetaOsph22 + ddbetaOsph122*R)/Power(R,2)
;

const auto
ddbeta123
=
-((cscth*(dbetaOsph23 + cotth*dbetaOsph13*R - ddbetaOsph123*R -
        cotth*betaOsph3[ijk]))/Power(R,2))
;

const auto
ddbeta131
=
ddbetaOsph131
;

const auto
ddbeta132
=
(-dbetaOsph32 + ddbetaOsph132*R)/Power(R,2)
;

const auto
ddbeta133
=
(cscth*(-dbetaOsph33 + ddbetaOsph133*R))/Power(R,2)
;

const auto
ddbeta221
=
ddbetaOsph221
;

const auto
ddbeta222
=
ddbetaOsph222/R
;

const auto
ddbeta223
=
(cscth*(-2*cotth*dbetaOsph23 + ddbetaOsph223 +
      (Power(cotth,2) + Power(cscth,2))*betaOsph3[ijk]))/R
;

const auto
ddbeta231
=
ddbetaOsph231
;

const auto
ddbeta232
=
ddbetaOsph232/R
;

const auto
ddbeta233
=
(cscth*(-(cotth*dbetaOsph33) + ddbetaOsph233))/R
;

const auto
ddbeta331
=
ddbetaOsph331
;

const auto
ddbeta332
=
ddbetaOsph332/R
;

const auto
ddbeta333
=
(cscth*ddbetaOsph333)/R
;


  });
});

#endif // #ifndef CURVCCZ4_SET_RHS_HXX

/* CurvCCZ4_set_rhs.hxx */
