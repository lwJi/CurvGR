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
R*sinth*epsOsph13[ijk]
;

const auto
eps22[ijk]
=
Power(R,2)*epsOsph22[ijk]
;

const auto
eps23[ijk]
=
Power(R,2)*sinth*epsOsph23[ijk]
;

const auto
eps33[ijk]
=
Power(R,2)*Power(sinth,2)*epsOsph33[ijk]
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
R*sinth*exAbOsph13[ijk]
;

const auto
exAb22[ijk]
=
Power(R,2)*exAbOsph22[ijk]
;

const auto
exAb23[ijk]
=
Power(R,2)*sinth*exAbOsph23[ijk]
;

const auto
exAb33[ijk]
=
Power(R,2)*Power(sinth,2)*exAbOsph33[ijk]
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
(cscth*LtOsph3[ijk])/R
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
(cscth*betaOsph3[ijk])/R
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
(cscth*BOsph3[ijk])/R
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
R*(costh*depsOsph123*R + (2*depsOsph223 + ddepsOsph1223*R)*sinth +
    2*costh*epsOsph23[ijk])
;

const auto
ddeps1233
=
R*sinth*(2*costh*depsOsph133*R + (2*depsOsph233 + ddepsOsph1233*R)*sinth +
    4*costh*epsOsph33[ijk])
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
    2*cos2th*epsOsph33[ijk])
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
(cscth*(-dbetaOsph23 - cotth*dbetaOsph13*R + ddbetaOsph123*R +
      cotth*betaOsph3[ijk]))/Power(R,2)
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


const auto
gamb11
=
1 + eps11[ijk]
;

const auto
gamb12
=
eps12[ijk]
;

const auto
gamb13
=
eps13[ijk]
;

const auto
gamb22
=
Power(R,2) + eps22[ijk]
;

const auto
gamb23
=
eps23[ijk]
;

const auto
gamb33
=
Power(R,2)*Power(sinth,2) + eps33[ijk]
;

const auto
dgamb111
=
deps111
;

const auto
dgamb112
=
deps112
;

const auto
dgamb113
=
deps113
;

const auto
dgamb122
=
deps122 - 2*R
;

const auto
dgamb123
=
deps123
;

const auto
dgamb133
=
deps133 - 2*R*Power(sinth,2)
;

const auto
dgamb211
=
deps211
;

const auto
dgamb212
=
deps212
;

const auto
dgamb213
=
deps213
;

const auto
dgamb222
=
deps222
;

const auto
dgamb223
=
deps223
;

const auto
dgamb233
=
deps233 - 2*costh*Power(R,2)*sinth
;

const auto
dgamb311
=
deps311
;

const auto
dgamb312
=
deps312
;

const auto
dgamb313
=
deps313
;

const auto
dgamb322
=
deps322
;

const auto
dgamb323
=
deps323
;

const auto
dgamb333
=
deps333
;

const auto
psim4
=
Power(E,-4*phi[ijk])
;

const auto
psi4
=
1/psim4
;

const auto
dgam111
=
(dgamb111 + 4*dphi1*gamb11)*psi4
;

const auto
dgam112
=
(dgamb112 + 4*dphi1*gamb12)*psi4
;

const auto
dgam113
=
(dgamb113 + 4*dphi1*gamb13)*psi4
;

const auto
dgam122
=
(dgamb122 + 4*dphi1*gamb22)*psi4
;

const auto
dgam123
=
(dgamb123 + 4*dphi1*gamb23)*psi4
;

const auto
dgam133
=
(dgamb133 + 4*dphi1*gamb33)*psi4
;

const auto
dgam211
=
(dgamb211 + 4*dphi2*gamb11)*psi4
;

const auto
dgam212
=
(dgamb212 + 4*dphi2*gamb12)*psi4
;

const auto
dgam213
=
(dgamb213 + 4*dphi2*gamb13)*psi4
;

const auto
dgam222
=
(dgamb222 + 4*dphi2*gamb22)*psi4
;

const auto
dgam223
=
(dgamb223 + 4*dphi2*gamb23)*psi4
;

const auto
dgam233
=
(dgamb233 + 4*dphi2*gamb33)*psi4
;

const auto
dgam311
=
(dgamb311 + 4*dphi3*gamb11)*psi4
;

const auto
dgam312
=
(dgamb312 + 4*dphi3*gamb12)*psi4
;

const auto
dgam313
=
(dgamb313 + 4*dphi3*gamb13)*psi4
;

const auto
dgam322
=
(dgamb322 + 4*dphi3*gamb22)*psi4
;

const auto
dgam323
=
(dgamb323 + 4*dphi3*gamb23)*psi4
;

const auto
dgam333
=
(dgamb333 + 4*dphi3*gamb33)*psi4
;

const auto
invgambdet
=
Power(cscth,2)/Power(R,4)
;

const auto
invgamb11
=
(-Power(gamb23,2) + gamb22*gamb33)*invgambdet
;

const auto
invgamb12
=
(gamb13*gamb23 - gamb12*gamb33)*invgambdet
;

const auto
invgamb13
=
(-(gamb13*gamb22) + gamb12*gamb23)*invgambdet
;

const auto
invgamb22
=
(-Power(gamb13,2) + gamb11*gamb33)*invgambdet
;

const auto
invgamb23
=
(gamb12*gamb13 - gamb11*gamb23)*invgambdet
;

const auto
invgamb33
=
(-Power(gamb12,2) + gamb11*gamb22)*invgambdet
;

const auto
invgam11
=
invgamb11*psim4
;

const auto
invgam12
=
invgamb12*psim4
;

const auto
invgam13
=
invgamb13*psim4
;

const auto
invgam22
=
invgamb22*psim4
;

const auto
invgam23
=
invgamb23*psim4
;

const auto
invgam33
=
invgamb33*psim4
;

const auto
gam11
=
gamb11*psi4
;

const auto
gam12
=
gamb12*psi4
;

const auto
gam13
=
gamb13*psi4
;

const auto
gam22
=
gamb22*psi4
;

const auto
gam23
=
gamb23*psi4
;

const auto
gam33
=
gamb33*psi4
;

const auto
GambDDD111
=
dgamb111/2.
;

const auto
GambDDD112
=
dgamb211/2.
;

const auto
GambDDD113
=
dgamb311/2.
;

const auto
GambDDD122
=
-0.5*dgamb122 + dgamb212
;

const auto
GambDDD123
=
(-dgamb123 + dgamb213 + dgamb312)/2.
;

const auto
GambDDD133
=
-0.5*dgamb133 + dgamb313
;

const auto
GambDDD211
=
dgamb112 - dgamb211/2.
;

const auto
GambDDD212
=
dgamb122/2.
;

const auto
GambDDD213
=
(dgamb123 - dgamb213 + dgamb312)/2.
;

const auto
GambDDD222
=
dgamb222/2.
;

const auto
GambDDD223
=
dgamb322/2.
;

const auto
GambDDD233
=
-0.5*dgamb233 + dgamb323
;

const auto
GambDDD311
=
dgamb113 - dgamb311/2.
;

const auto
GambDDD312
=
(dgamb123 + dgamb213 - dgamb312)/2.
;

const auto
GambDDD313
=
dgamb133/2.
;

const auto
GambDDD322
=
dgamb223 - dgamb322/2.
;

const auto
GambDDD323
=
dgamb233/2.
;

const auto
GambDDD333
=
dgamb333/2.
;

const auto
Gamb111
=
GambDDD111*invgamb11 + GambDDD211*invgamb12 + GambDDD311*invgamb13
;

const auto
Gamb112
=
GambDDD112*invgamb11 + GambDDD212*invgamb12 + GambDDD312*invgamb13
;

const auto
Gamb113
=
GambDDD113*invgamb11 + GambDDD213*invgamb12 + GambDDD313*invgamb13
;

const auto
Gamb122
=
GambDDD122*invgamb11 + GambDDD222*invgamb12 + GambDDD322*invgamb13
;

const auto
Gamb123
=
GambDDD123*invgamb11 + GambDDD223*invgamb12 + GambDDD323*invgamb13
;

const auto
Gamb133
=
GambDDD133*invgamb11 + GambDDD233*invgamb12 + GambDDD333*invgamb13
;

const auto
Gamb211
=
GambDDD111*invgamb12 + GambDDD211*invgamb22 + GambDDD311*invgamb23
;

const auto
Gamb212
=
GambDDD112*invgamb12 + GambDDD212*invgamb22 + GambDDD312*invgamb23
;

const auto
Gamb213
=
GambDDD113*invgamb12 + GambDDD213*invgamb22 + GambDDD313*invgamb23
;

const auto
Gamb222
=
GambDDD122*invgamb12 + GambDDD222*invgamb22 + GambDDD322*invgamb23
;

const auto
Gamb223
=
GambDDD123*invgamb12 + GambDDD223*invgamb22 + GambDDD323*invgamb23
;

const auto
Gamb233
=
GambDDD133*invgamb12 + GambDDD233*invgamb22 + GambDDD333*invgamb23
;

const auto
Gamb311
=
GambDDD111*invgamb13 + GambDDD211*invgamb23 + GambDDD311*invgamb33
;

const auto
Gamb312
=
GambDDD112*invgamb13 + GambDDD212*invgamb23 + GambDDD312*invgamb33
;

const auto
Gamb313
=
GambDDD113*invgamb13 + GambDDD213*invgamb23 + GambDDD313*invgamb33
;

const auto
Gamb322
=
GambDDD122*invgamb13 + GambDDD222*invgamb23 + GambDDD322*invgamb33
;

const auto
Gamb323
=
GambDDD123*invgamb13 + GambDDD223*invgamb23 + GambDDD323*invgamb33
;

const auto
Gamb333
=
GambDDD133*invgamb13 + GambDDD233*invgamb23 + GambDDD333*invgamb33
;

const auto
GamDDD111
=
dgam111/2.
;

const auto
GamDDD112
=
dgam211/2.
;

const auto
GamDDD113
=
dgam311/2.
;

const auto
GamDDD122
=
-0.5*dgam122 + dgam212
;

const auto
GamDDD123
=
(-dgam123 + dgam213 + dgam312)/2.
;

const auto
GamDDD133
=
-0.5*dgam133 + dgam313
;

const auto
GamDDD211
=
dgam112 - dgam211/2.
;

const auto
GamDDD212
=
dgam122/2.
;

const auto
GamDDD213
=
(dgam123 - dgam213 + dgam312)/2.
;

const auto
GamDDD222
=
dgam222/2.
;

const auto
GamDDD223
=
dgam322/2.
;

const auto
GamDDD233
=
-0.5*dgam233 + dgam323
;

const auto
GamDDD311
=
dgam113 - dgam311/2.
;

const auto
GamDDD312
=
(dgam123 + dgam213 - dgam312)/2.
;

const auto
GamDDD313
=
dgam133/2.
;

const auto
GamDDD322
=
dgam223 - dgam322/2.
;

const auto
GamDDD323
=
dgam233/2.
;

const auto
GamDDD333
=
dgam333/2.
;

const auto
Gam111
=
GamDDD111*invgam11 + GamDDD211*invgam12 + GamDDD311*invgam13
;

const auto
Gam112
=
GamDDD112*invgam11 + GamDDD212*invgam12 + GamDDD312*invgam13
;

const auto
Gam113
=
GamDDD113*invgam11 + GamDDD213*invgam12 + GamDDD313*invgam13
;

const auto
Gam122
=
GamDDD122*invgam11 + GamDDD222*invgam12 + GamDDD322*invgam13
;

const auto
Gam123
=
GamDDD123*invgam11 + GamDDD223*invgam12 + GamDDD323*invgam13
;

const auto
Gam133
=
GamDDD133*invgam11 + GamDDD233*invgam12 + GamDDD333*invgam13
;

const auto
Gam211
=
GamDDD111*invgam12 + GamDDD211*invgam22 + GamDDD311*invgam23
;

const auto
Gam212
=
GamDDD112*invgam12 + GamDDD212*invgam22 + GamDDD312*invgam23
;

const auto
Gam213
=
GamDDD113*invgam12 + GamDDD213*invgam22 + GamDDD313*invgam23
;

const auto
Gam222
=
GamDDD122*invgam12 + GamDDD222*invgam22 + GamDDD322*invgam23
;

const auto
Gam223
=
GamDDD123*invgam12 + GamDDD223*invgam22 + GamDDD323*invgam23
;

const auto
Gam233
=
GamDDD133*invgam12 + GamDDD233*invgam22 + GamDDD333*invgam23
;

const auto
Gam311
=
GamDDD111*invgam13 + GamDDD211*invgam23 + GamDDD311*invgam33
;

const auto
Gam312
=
GamDDD112*invgam13 + GamDDD212*invgam23 + GamDDD312*invgam33
;

const auto
Gam313
=
GamDDD113*invgam13 + GamDDD213*invgam23 + GamDDD313*invgam33
;

const auto
Gam322
=
GamDDD122*invgam13 + GamDDD222*invgam23 + GamDDD322*invgam33
;

const auto
Gam323
=
GamDDD123*invgam13 + GamDDD223*invgam23 + GamDDD323*invgam33
;

const auto
Gam333
=
GamDDD133*invgam13 + GamDDD233*invgam23 + GamDDD333*invgam33
;

const auto
exAbUU11
=
Power(invgamb11,2)*exAb11[ijk] + 2*invgamb11*invgamb12*exAb12[ijk] +
  2*invgamb11*invgamb13*exAb13[ijk] + Power(invgamb12,2)*exAb22[ijk] +
  2*invgamb12*invgamb13*exAb23[ijk] + Power(invgamb13,2)*exAb33[ijk]
;

const auto
exAbUU12
=
invgamb11*invgamb12*exAb11[ijk] +
  (Power(invgamb12,2) + invgamb11*invgamb22)*exAb12[ijk] +
  invgamb12*invgamb13*exAb13[ijk] + invgamb11*invgamb23*exAb13[ijk] +
  invgamb12*invgamb22*exAb22[ijk] + invgamb13*invgamb22*exAb23[ijk] +
  invgamb12*invgamb23*exAb23[ijk] + invgamb13*invgamb23*exAb33[ijk]
;

const auto
exAbUU13
=
invgamb11*invgamb13*exAb11[ijk] +
  (invgamb12*invgamb13 + invgamb11*invgamb23)*exAb12[ijk] +
  Power(invgamb13,2)*exAb13[ijk] + invgamb11*invgamb33*exAb13[ijk] +
  invgamb12*invgamb23*exAb22[ijk] + invgamb13*invgamb23*exAb23[ijk] +
  invgamb12*invgamb33*exAb23[ijk] + invgamb13*invgamb33*exAb33[ijk]
;

const auto
exAbUU22
=
Power(invgamb12,2)*exAb11[ijk] + 2*invgamb12*invgamb22*exAb12[ijk] +
  2*invgamb12*invgamb23*exAb13[ijk] + Power(invgamb22,2)*exAb22[ijk] +
  2*invgamb22*invgamb23*exAb23[ijk] + Power(invgamb23,2)*exAb33[ijk]
;

const auto
exAbUU23
=
invgamb12*invgamb13*exAb11[ijk] +
  (invgamb13*invgamb22 + invgamb12*invgamb23)*exAb12[ijk] +
  invgamb13*invgamb23*exAb13[ijk] + invgamb12*invgamb33*exAb13[ijk] +
  invgamb22*invgamb23*exAb22[ijk] + Power(invgamb23,2)*exAb23[ijk] +
  invgamb22*invgamb33*exAb23[ijk] + invgamb23*invgamb33*exAb33[ijk]
;

const auto
exAbUU33
=
Power(invgamb13,2)*exAb11[ijk] + 2*invgamb13*invgamb23*exAb12[ijk] +
  2*invgamb13*invgamb33*exAb13[ijk] + Power(invgamb23,2)*exAb22[ijk] +
  2*invgamb23*invgamb33*exAb23[ijk] + Power(invgamb33,2)*exAb33[ijk]
;


  });
});

#endif // #ifndef CURVCCZ4_SET_RHS_HXX

/* CurvCCZ4_set_rhs.hxx */
