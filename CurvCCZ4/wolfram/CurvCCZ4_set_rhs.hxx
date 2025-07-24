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
eps11
=
epsOsph11[ijk]
;

const auto
eps12
=
R*epsOsph12[ijk]
;

const auto
eps13
=
R*sinth*epsOsph13[ijk]
;

const auto
eps22
=
Power(R,2)*epsOsph22[ijk]
;

const auto
eps23
=
Power(R,2)*sinth*epsOsph23[ijk]
;

const auto
eps33
=
Power(R,2)*Power(sinth,2)*epsOsph33[ijk]
;

const auto
exAb11
=
exAbOsph11[ijk]
;

const auto
exAb12
=
R*exAbOsph12[ijk]
;

const auto
exAb13
=
R*sinth*exAbOsph13[ijk]
;

const auto
exAb22
=
Power(R,2)*exAbOsph22[ijk]
;

const auto
exAb23
=
Power(R,2)*sinth*exAbOsph23[ijk]
;

const auto
exAb33
=
Power(R,2)*Power(sinth,2)*exAbOsph33[ijk]
;

const auto
Lt1
=
LtOsph1[ijk]
;

const auto
Lt2
=
LtOsph2[ijk]/R
;

const auto
Lt3
=
(cscth*LtOsph3[ijk])/R
;

const auto
beta1
=
betaOsph1[ijk]
;

const auto
beta2
=
betaOsph2[ijk]/R
;

const auto
beta3
=
(cscth*betaOsph3[ijk])/R
;

const auto
B1
=
BOsph1[ijk]
;

const auto
B2
=
BOsph2[ijk]/R
;

const auto
B3
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
1 + eps11
;

const auto
gamb12
=
eps12
;

const auto
gamb13
=
eps13
;

const auto
gamb22
=
eps22 + Power(R,2)
;

const auto
gamb23
=
eps23
;

const auto
gamb33
=
eps33 + Power(R,2)*Power(sinth,2)
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
exAb11*Power(invgamb11,2) + 2*exAb12*invgamb11*invgamb12 +
  exAb22*Power(invgamb12,2) + 2*exAb13*invgamb11*invgamb13 +
  2*exAb23*invgamb12*invgamb13 + exAb33*Power(invgamb13,2)
;

const auto
exAbUU12
=
exAb11*invgamb11*invgamb12 + exAb13*invgamb12*invgamb13 +
  exAb22*invgamb12*invgamb22 + exAb23*invgamb13*invgamb22 +
  exAb12*(Power(invgamb12,2) + invgamb11*invgamb22) +
  exAb13*invgamb11*invgamb23 + exAb23*invgamb12*invgamb23 +
  exAb33*invgamb13*invgamb23
;

const auto
exAbUU13
=
exAb11*invgamb11*invgamb13 + exAb12*invgamb12*invgamb13 +
  exAb13*Power(invgamb13,2) + exAb12*invgamb11*invgamb23 +
  exAb22*invgamb12*invgamb23 + exAb23*invgamb13*invgamb23 +
  exAb13*invgamb11*invgamb33 + exAb23*invgamb12*invgamb33 +
  exAb33*invgamb13*invgamb33
;

const auto
exAbUU22
=
exAb11*Power(invgamb12,2) + 2*exAb12*invgamb12*invgamb22 +
  exAb22*Power(invgamb22,2) + 2*exAb13*invgamb12*invgamb23 +
  2*exAb23*invgamb22*invgamb23 + exAb33*Power(invgamb23,2)
;

const auto
exAbUU23
=
exAb11*invgamb12*invgamb13 + exAb12*invgamb13*invgamb22 +
  exAb12*invgamb12*invgamb23 + exAb13*invgamb13*invgamb23 +
  exAb22*invgamb22*invgamb23 + exAb23*Power(invgamb23,2) +
  exAb13*invgamb12*invgamb33 + exAb23*invgamb22*invgamb33 +
  exAb33*invgamb23*invgamb33
;

const auto
exAbUU33
=
exAb11*Power(invgamb13,2) + 2*exAb12*invgamb13*invgamb23 +
  exAb22*Power(invgamb23,2) + 2*exAb13*invgamb13*invgamb33 +
  2*exAb23*invgamb23*invgamb33 + exAb33*Power(invgamb33,2)
;


const auto
trbDbeta
=
beta2*cotth + dbeta11 + dbeta22 + dbeta33 + (2*beta1)/R
;

const auto
bDtrbDbeta1
=
cotth*dbeta12 + ddbeta111 + ddbeta122 + ddbeta133 - (2*beta1)/Power(R,2) +
  (2*dbeta11)/R
;

const auto
bDtrbDbeta2
=
-beta2 - beta2*Power(cotth,2) + cotth*dbeta22 + ddbeta121 + ddbeta222 +
  ddbeta233 + (2*dbeta21)/R
;

const auto
bDtrbDbeta3
=
cotth*dbeta32 + ddbeta131 + ddbeta232 + ddbeta333 + (2*dbeta31)/R
;

const auto
bDbDphi11
=
ddphi11 - dphi1*Gamb111 - dphi2*Gamb211 - dphi3*Gamb311
;

const auto
bDbDphi12
=
ddphi12 - dphi1*Gamb112 - dphi2*Gamb212 - dphi3*Gamb312
;

const auto
bDbDphi13
=
ddphi13 - dphi1*Gamb113 - dphi2*Gamb213 - dphi3*Gamb313
;

const auto
bDbDphi22
=
ddphi22 - dphi1*Gamb122 - dphi2*Gamb222 - dphi3*Gamb322
;

const auto
bDbDphi23
=
ddphi23 - dphi1*Gamb123 - dphi2*Gamb223 - dphi3*Gamb323
;

const auto
bDbDphi33
=
ddphi33 - dphi1*Gamb133 - dphi2*Gamb233 - dphi3*Gamb333
;

const auto
bDbDalpha11
=
ddalpha11 - dalpha1*Gamb111 - dalpha2*Gamb211 - dalpha3*Gamb311
;

const auto
bDbDalpha12
=
ddalpha12 - dalpha1*Gamb112 - dalpha2*Gamb212 - dalpha3*Gamb312
;

const auto
bDbDalpha13
=
ddalpha13 - dalpha1*Gamb113 - dalpha2*Gamb213 - dalpha3*Gamb313
;

const auto
bDbDalpha22
=
ddalpha22 - dalpha1*Gamb122 - dalpha2*Gamb222 - dalpha3*Gamb322
;

const auto
bDbDalpha23
=
ddalpha23 - dalpha1*Gamb123 - dalpha2*Gamb223 - dalpha3*Gamb323
;

const auto
bDbDalpha33
=
ddalpha33 - dalpha1*Gamb133 - dalpha2*Gamb233 - dalpha3*Gamb333
;

const auto
trexAb
=
exAb11*invgamb11 + 2*exAb12*invgamb12 + 2*exAb13*invgamb13 +
  exAb22*invgamb22 + 2*exAb23*invgamb23 + exAb33*invgamb33
;

const auto
trbDbDphi
=
bDbDphi11*invgamb11 + 2*bDbDphi12*invgamb12 + 2*bDbDphi13*invgamb13 +
  bDbDphi22*invgamb22 + 2*bDbDphi23*invgamb23 + bDbDphi33*invgamb33
;

const auto
trbDphibDphi
=
Power(dphi1,2)*invgamb11 + 2*dphi1*(dphi2*invgamb12 + dphi3*invgamb13) +
  Power(dphi2,2)*invgamb22 + 2*dphi2*dphi3*invgamb23 +
  Power(dphi3,2)*invgamb33
;

const auto
trbDbDalpha
=
bDbDalpha11*invgamb11 + 2*bDbDalpha12*invgamb12 + 2*bDbDalpha13*invgamb13 +
  bDbDalpha22*invgamb22 + 2*bDbDalpha23*invgamb23 + bDbDalpha33*invgamb33
;


const auto
hDgamb111
=
deps111
;

const auto
hDgamb112
=
deps112 - eps12/R
;

const auto
hDgamb113
=
deps113 - eps13/R
;

const auto
hDgamb122
=
deps122 - (2*eps22)/R
;

const auto
hDgamb123
=
deps123 - (2*eps23)/R
;

const auto
hDgamb133
=
deps133 - (2*eps33)/R
;

const auto
hDgamb211
=
deps211 - (2*eps12)/R
;

const auto
hDgamb212
=
deps212 - eps22/R + eps11*R
;

const auto
hDgamb213
=
deps213 - cotth*eps13 - eps23/R
;

const auto
hDgamb222
=
deps222 + 2*eps12*R
;

const auto
hDgamb223
=
deps223 - cotth*eps23 + eps13*R
;

const auto
hDgamb233
=
deps233 - 2*cotth*eps33
;

const auto
hDgamb311
=
deps311 - (2*eps13)/R
;

const auto
hDgamb312
=
deps312 - cotth*eps13 - eps23/R
;

const auto
hDgamb313
=
deps313 - eps33/R + costh*eps12*sinth + eps11*R*Power(sinth,2)
;

const auto
hDgamb322
=
deps322 - 2*cotth*eps23
;

const auto
hDgamb323
=
deps323 - cotth*eps33 + costh*eps22*sinth + eps12*R*Power(sinth,2)
;

const auto
hDgamb333
=
deps333 + 2*eps13*R*Power(sinth,2) + eps23*Sin(2*T)
;

const auto
hDLt11
=
dLt11
;

const auto
hDLt12
=
dLt12 + Lt2/R
;

const auto
hDLt13
=
dLt13 + Lt3/R
;

const auto
hDLt21
=
dLt21 - Lt2*R
;

const auto
hDLt22
=
dLt22 + Lt1/R
;

const auto
hDLt23
=
dLt23 + cotth*Lt3
;

const auto
hDLt31
=
dLt31 - Lt3*R*Power(sinth,2)
;

const auto
hDLt32
=
dLt32 - costh*Lt3*sinth
;

const auto
hDLt33
=
dLt33 + cotth*Lt2 + Lt1/R
;

const auto
hDbeta11
=
dbeta11
;

const auto
hDbeta12
=
dbeta12 + beta2/R
;

const auto
hDbeta13
=
dbeta13 + beta3/R
;

const auto
hDbeta21
=
dbeta21 - beta2*R
;

const auto
hDbeta22
=
dbeta22 + beta1/R
;

const auto
hDbeta23
=
beta3*cotth + dbeta23
;

const auto
hDbeta31
=
dbeta31 - beta3*R*Power(sinth,2)
;

const auto
hDbeta32
=
dbeta32 - beta3*costh*sinth
;

const auto
hDbeta33
=
beta2*cotth + dbeta33 + beta1/R
;

const auto
hDB11
=
dB11
;

const auto
hDB12
=
dB12 + B2/R
;

const auto
hDB13
=
dB13 + B3/R
;

const auto
hDB21
=
dB21 - B2*R
;

const auto
hDB22
=
dB22 + B1/R
;

const auto
hDB23
=
B3*cotth + dB23
;

const auto
hDB31
=
dB31 - B3*R*Power(sinth,2)
;

const auto
hDB32
=
dB32 - B3*costh*sinth
;

const auto
hDB33
=
B2*cotth + dB33 + B1/R
;

const auto
dhDgamb1111
=
ddeps1111
;

const auto
dhDgamb1112
=
ddeps1112 + (eps12 - deps112*R)/Power(R,2)
;

const auto
dhDgamb1113
=
ddeps1113 + (eps13 - deps113*R)/Power(R,2)
;

const auto
dhDgamb1122
=
ddeps1122 + (2*(eps22 - deps122*R))/Power(R,2)
;

const auto
dhDgamb1123
=
ddeps1123 + (2*(eps23 - deps123*R))/Power(R,2)
;

const auto
dhDgamb1133
=
ddeps1133 + (2*(eps33 - deps133*R))/Power(R,2)
;

const auto
dhDgamb1211
=
ddeps1211 + (2*(eps12 - deps112*R))/Power(R,2)
;

const auto
dhDgamb1212
=
ddeps1212 + eps11 + (eps22 - deps122*R + deps111*Power(R,3))/Power(R,2)
;

const auto
dhDgamb1213
=
ddeps1213 - cotth*deps113 + (eps23 - deps123*R)/Power(R,2)
;

const auto
dhDgamb1222
=
ddeps1222 + 2*(eps12 + deps112*R)
;

const auto
dhDgamb1223
=
ddeps1223 - cotth*deps123 + eps13 + deps113*R
;

const auto
dhDgamb1233
=
ddeps1233 - 2*cotth*deps133
;

const auto
dhDgamb1311
=
ddeps1311 + (2*(eps13 - deps113*R))/Power(R,2)
;

const auto
dhDgamb1312
=
ddeps1312 - cotth*deps113 + (eps23 - deps123*R)/Power(R,2)
;

const auto
dhDgamb1313
=
ddeps1313 + eps33/Power(R,2) - deps133/R + costh*deps112*sinth +
  (eps11 + deps111*R)*Power(sinth,2)
;

const auto
dhDgamb1322
=
ddeps1322 - 2*cotth*deps123
;

const auto
dhDgamb1323
=
ddeps1323 - cotth*deps133 + costh*deps122*sinth + eps12*Power(sinth,2) +
  deps112*R*Power(sinth,2)
;

const auto
dhDgamb1333
=
ddeps1333 + 2*(eps13 + deps113*R)*Power(sinth,2) + deps123*Sin(2*T)
;

const auto
dhDgamb2211
=
ddeps2211 - (2*deps212)/R
;

const auto
dhDgamb2212
=
ddeps2212 - deps222/R + deps211*R
;

const auto
dhDgamb2213
=
ddeps2213 - cotth*deps213 + Power(cscth,2)*eps13 - deps223/R
;

const auto
dhDgamb2222
=
ddeps2222 + 2*deps212*R
;

const auto
dhDgamb2223
=
ddeps2223 - cotth*deps223 + Power(cscth,2)*eps23 + deps213*R
;

const auto
dhDgamb2233
=
ddeps2233 - 2*cotth*deps233 + 2*Power(cscth,2)*eps33
;

const auto
dhDgamb2311
=
ddeps2311 - (2*deps213)/R
;

const auto
dhDgamb2312
=
ddeps2312 - cotth*deps213 + Power(cscth,2)*eps13 - deps223/R
;

const auto
dhDgamb2313
=
ddeps2313 + Power(costh,2)*eps12 - deps233/R + costh*deps212*sinth +
  (-eps12 + deps211*R)*Power(sinth,2) + eps11*R*Sin(2*T)
;

const auto
dhDgamb2322
=
ddeps2322 - 2*cotth*deps223 + 2*Power(cscth,2)*eps23
;

const auto
dhDgamb2323
=
ddeps2323 - cotth*deps233 + Power(costh,2)*eps22 + Power(cscth,2)*eps33 +
  costh*deps222*sinth - eps22*Power(sinth,2) + deps212*R*Power(sinth,2) +
  eps12*R*Sin(2*T)
;

const auto
dhDgamb2333
=
ddeps2333 + deps213*R + cos2th*(2*eps23 - deps213*R) +
  (deps223 + 2*eps13*R)*Sin(2*T)
;

const auto
dhDgamb3311
=
ddeps3311 - (2*deps313)/R
;

const auto
dhDgamb3312
=
ddeps3312 - cotth*deps313 - deps323/R
;

const auto
dhDgamb3313
=
ddeps3313 - deps333/R + costh*deps312*sinth + deps311*R*Power(sinth,2)
;

const auto
dhDgamb3322
=
ddeps3322 - 2*cotth*deps323
;

const auto
dhDgamb3323
=
ddeps3323 - cotth*deps333 + costh*deps322*sinth + deps312*R*Power(sinth,2)
;

const auto
dhDgamb3333
=
ddeps3333 + 2*deps313*R*Power(sinth,2) + deps323*Sin(2*T)
;

const auto
hDhDgamb1111
=
dhDgamb1111
;

const auto
hDhDgamb1112
=
dhDgamb1112 - hDgamb112/R
;

const auto
hDhDgamb1113
=
dhDgamb1113 - hDgamb113/R
;

const auto
hDhDgamb1122
=
dhDgamb1122 - (2*hDgamb122)/R
;

const auto
hDhDgamb1123
=
dhDgamb1123 - (2*hDgamb123)/R
;

const auto
hDhDgamb1133
=
dhDgamb1133 - (2*hDgamb133)/R
;

const auto
hDhDgamb1211
=
dhDgamb1211 - hDgamb211/R
;

const auto
hDhDgamb1212
=
dhDgamb1212 - (2*hDgamb212)/R
;

const auto
hDhDgamb1213
=
dhDgamb1213 - (2*hDgamb213)/R
;

const auto
hDhDgamb1222
=
dhDgamb1222 - (3*hDgamb222)/R
;

const auto
hDhDgamb1223
=
dhDgamb1223 - (3*hDgamb223)/R
;

const auto
hDhDgamb1233
=
dhDgamb1233 - (3*hDgamb233)/R
;

const auto
hDhDgamb1311
=
dhDgamb1311 - hDgamb311/R
;

const auto
hDhDgamb1312
=
dhDgamb1312 - (2*hDgamb312)/R
;

const auto
hDhDgamb1313
=
dhDgamb1313 - (2*hDgamb313)/R
;

const auto
hDhDgamb1322
=
dhDgamb1322 - (3*hDgamb322)/R
;

const auto
hDhDgamb1323
=
dhDgamb1323 - (3*hDgamb323)/R
;

const auto
hDhDgamb1333
=
dhDgamb1333 - (3*hDgamb333)/R
;

const auto
hDhDgamb2211
=
dhDgamb2211 - (2*hDgamb212)/R + hDgamb111*R
;

const auto
hDhDgamb2212
=
dhDgamb2212 - hDgamb222/R + (hDgamb112 + hDgamb211)*R
;

const auto
hDhDgamb2213
=
dhDgamb2213 - cotth*hDgamb213 - hDgamb223/R + hDgamb113*R
;

const auto
hDhDgamb2222
=
dhDgamb2222 + (hDgamb122 + 2*hDgamb212)*R
;

const auto
hDhDgamb2223
=
dhDgamb2223 - cotth*hDgamb223 + (hDgamb123 + hDgamb213)*R
;

const auto
hDhDgamb2233
=
dhDgamb2233 - 2*cotth*hDgamb233 + hDgamb133*R
;

const auto
hDhDgamb2311
=
dhDgamb2311 - cotth*hDgamb311 - (2*hDgamb312)/R
;

const auto
hDhDgamb2312
=
dhDgamb2312 - cotth*hDgamb312 - hDgamb322/R + hDgamb311*R
;

const auto
hDhDgamb2313
=
dhDgamb2313 - 2*cotth*hDgamb313 - hDgamb323/R
;

const auto
hDhDgamb2322
=
dhDgamb2322 - cotth*hDgamb322 + 2*hDgamb312*R
;

const auto
hDhDgamb2323
=
dhDgamb2323 - 2*cotth*hDgamb323 + hDgamb313*R
;

const auto
hDhDgamb2333
=
dhDgamb2333 - 3*cotth*hDgamb333
;

const auto
hDhDgamb3311
=
dhDgamb3311 - (2*hDgamb313)/R + costh*hDgamb211*sinth +
  hDgamb111*R*Power(sinth,2)
;

const auto
hDhDgamb3312
=
dhDgamb3312 - cotth*hDgamb313 - hDgamb323/R + costh*hDgamb212*sinth +
  hDgamb112*R*Power(sinth,2)
;

const auto
hDhDgamb3313
=
dhDgamb3313 - hDgamb333/R + costh*(hDgamb213 + hDgamb312)*sinth +
  (hDgamb113 + hDgamb311)*R*Power(sinth,2)
;

const auto
hDhDgamb3322
=
dhDgamb3322 - 2*cotth*hDgamb323 + costh*hDgamb222*sinth +
  hDgamb122*R*Power(sinth,2)
;

const auto
hDhDgamb3323
=
dhDgamb3323 - cotth*hDgamb333 + costh*(hDgamb223 + hDgamb322)*sinth +
  hDgamb123*R*Power(sinth,2) + hDgamb312*R*Power(sinth,2)
;

const auto
hDhDgamb3333
=
dhDgamb3333 + costh*hDgamb233*sinth +
  (hDgamb133 + 2*hDgamb313)*R*Power(sinth,2) + hDgamb323*Sin(2*T)
;

const auto
hDhDbeta111
=
ddbeta111
;

const auto
hDhDbeta112
=
ddbeta112 + (2*dbeta12)/R
;

const auto
hDhDbeta113
=
ddbeta113 + (2*dbeta13)/R
;

const auto
hDhDbeta121
=
ddbeta121 - dbeta21/R - dbeta12*R
;

const auto
hDhDbeta122
=
ddbeta122 + (-beta1 + dbeta11*R)/Power(R,2)
;

const auto
hDhDbeta123
=
cotth*dbeta13 + ddbeta123
;

const auto
hDhDbeta131
=
ddbeta131 - dbeta31/R - dbeta13*R*Power(sinth,2)
;

const auto
hDhDbeta132
=
ddbeta132 - costh*dbeta13*sinth
;

const auto
hDhDbeta133
=
cotth*dbeta12 + ddbeta133 + (-beta1 + dbeta11*R)/Power(R,2)
;

const auto
hDhDbeta221
=
-beta1 + ddbeta221 + (dbeta11 - 2*dbeta22)*R
;

const auto
hDhDbeta222
=
ddbeta222 + (2*dbeta21)/R + dbeta12*R
;

const auto
hDhDbeta223
=
2*cotth*dbeta23 + ddbeta223 + dbeta13*R
;

const auto
hDhDbeta231
=
-(cotth*dbeta31) + ddbeta231 - dbeta32*R - dbeta23*R*Power(sinth,2)
;

const auto
hDhDbeta232
=
-(cotth*dbeta32) + ddbeta232 + dbeta31/R - costh*dbeta23*sinth
;

const auto
hDhDbeta233
=
-(beta2*Power(cscth,2)) + cotth*dbeta22 + ddbeta233 + dbeta21/R
;

const auto
hDhDbeta331
=
ddbeta331 + costh*(dbeta21 - 2*beta2*R)*sinth -
  (beta1 - dbeta11*R + 2*dbeta33*R)*Power(sinth,2)
;

const auto
hDhDbeta332
=
-(beta2*Power(costh,2)) + ddbeta332 + costh*(dbeta22 - 2*dbeta33)*sinth +
  (beta2 + dbeta12*R)*Power(sinth,2)
;

const auto
hDhDbeta333
=
2*cotth*dbeta32 + ddbeta333 + (2*dbeta31)/R + costh*dbeta23*sinth +
  dbeta13*R*Power(sinth,2)
;


const auto
DGamDDD111
=
hDgamb111
;

const auto
DGamDDD112
=
hDgamb211
;

const auto
DGamDDD113
=
hDgamb311
;

const auto
DGamDDD122
=
-hDgamb122 + 2*hDgamb212
;

const auto
DGamDDD123
=
-hDgamb123 + hDgamb213 + hDgamb312
;

const auto
DGamDDD133
=
-hDgamb133 + 2*hDgamb313
;

const auto
DGamDDD211
=
2*hDgamb112 - hDgamb211
;

const auto
DGamDDD212
=
hDgamb122
;

const auto
DGamDDD213
=
hDgamb123 - hDgamb213 + hDgamb312
;

const auto
DGamDDD222
=
hDgamb222
;

const auto
DGamDDD223
=
hDgamb322
;

const auto
DGamDDD233
=
-hDgamb233 + 2*hDgamb323
;

const auto
DGamDDD311
=
2*hDgamb113 - hDgamb311
;

const auto
DGamDDD312
=
hDgamb123 + hDgamb213 - hDgamb312
;

const auto
DGamDDD313
=
hDgamb133
;

const auto
DGamDDD322
=
2*hDgamb223 - hDgamb322
;

const auto
DGamDDD323
=
hDgamb233
;

const auto
DGamDDD333
=
hDgamb333
;

const auto
DGam111
=
DGamDDD111*invgamb11 + DGamDDD211*invgamb12 + DGamDDD311*invgamb13
;

const auto
DGam112
=
DGamDDD112*invgamb11 + DGamDDD212*invgamb12 + DGamDDD312*invgamb13
;

const auto
DGam113
=
DGamDDD113*invgamb11 + DGamDDD213*invgamb12 + DGamDDD313*invgamb13
;

const auto
DGam122
=
DGamDDD122*invgamb11 + DGamDDD222*invgamb12 + DGamDDD322*invgamb13
;

const auto
DGam123
=
DGamDDD123*invgamb11 + DGamDDD223*invgamb12 + DGamDDD323*invgamb13
;

const auto
DGam133
=
DGamDDD133*invgamb11 + DGamDDD233*invgamb12 + DGamDDD333*invgamb13
;

const auto
DGam211
=
DGamDDD111*invgamb12 + DGamDDD211*invgamb22 + DGamDDD311*invgamb23
;

const auto
DGam212
=
DGamDDD112*invgamb12 + DGamDDD212*invgamb22 + DGamDDD312*invgamb23
;

const auto
DGam213
=
DGamDDD113*invgamb12 + DGamDDD213*invgamb22 + DGamDDD313*invgamb23
;

const auto
DGam222
=
DGamDDD122*invgamb12 + DGamDDD222*invgamb22 + DGamDDD322*invgamb23
;

const auto
DGam223
=
DGamDDD123*invgamb12 + DGamDDD223*invgamb22 + DGamDDD323*invgamb23
;

const auto
DGam233
=
DGamDDD133*invgamb12 + DGamDDD233*invgamb22 + DGamDDD333*invgamb23
;

const auto
DGam311
=
DGamDDD111*invgamb13 + DGamDDD211*invgamb23 + DGamDDD311*invgamb33
;

const auto
DGam312
=
DGamDDD112*invgamb13 + DGamDDD212*invgamb23 + DGamDDD312*invgamb33
;

const auto
DGam313
=
DGamDDD113*invgamb13 + DGamDDD213*invgamb23 + DGamDDD313*invgamb33
;

const auto
DGam322
=
DGamDDD122*invgamb13 + DGamDDD222*invgamb23 + DGamDDD322*invgamb33
;

const auto
DGam323
=
DGamDDD123*invgamb13 + DGamDDD223*invgamb23 + DGamDDD323*invgamb33
;

const auto
DGam333
=
DGamDDD133*invgamb13 + DGamDDD233*invgamb23 + DGamDDD333*invgamb33
;

const auto
trDGam1
=
DGam111*invgamb11 + 2*DGam112*invgamb12 + 2*DGam113*invgamb13 +
  DGam122*invgamb22 + 2*DGam123*invgamb23 + DGam133*invgamb33
;

const auto
trDGam2
=
DGam211*invgamb11 + 2*DGam212*invgamb12 + 2*DGam213*invgamb13 +
  DGam222*invgamb22 + 2*DGam223*invgamb23 + DGam233*invgamb33
;

const auto
trDGam3
=
DGam311*invgamb11 + 2*DGam312*invgamb12 + 2*DGam313*invgamb13 +
  DGam322*invgamb22 + 2*DGam323*invgamb23 + DGam333*invgamb33
;

const auto
ZU1
=
(psim4*(Lt1 - trDGam1))/2.
;

const auto
ZU2
=
(psim4*(Lt2 - trDGam2))/2.
;

const auto
ZU3
=
(psim4*(Lt3 - trDGam3))/2.
;

const auto
ZD1
=
gam11*ZU1 + gam12*ZU2 + gam13*ZU3
;

const auto
ZD2
=
gam12*ZU1 + gam22*ZU2 + gam23*ZU3
;

const auto
ZD3
=
gam13*ZU1 + gam23*ZU2 + gam33*ZU3
;


const auto
RZ11
=
(2*(R*(-4*dphi1*ZD1 + gam11*Gam111*ZU1 + gam11*Gam112*ZU2 +
         gam11*Gam113*ZU3) + gam12*
       (Gam211*R*ZU1 - ZU2 + Gam212*R*ZU2 + Gam213*R*ZU3) +
      gam13*(Gam311*R*ZU1 + Gam312*R*ZU2 - ZU3 + Gam313*R*ZU3)))/R
;

const auto
RZ12
=
-4*dphi2*ZD1 - 4*dphi1*ZD2 + gam11*Gam112*ZU1 + Gam111*gam12*ZU1 +
  gam12*Gam212*ZU1 + Gam211*gam22*ZU1 + gam23*Gam311*ZU1 +
  gam13*Gam312*ZU1 - (gam12*ZU1)/R + Gam112*gam12*ZU2 + gam11*Gam122*ZU2 +
  Gam212*gam22*ZU2 + gam12*Gam222*ZU2 + gam23*Gam312*ZU2 +
  gam13*Gam322*ZU2 - (gam22*ZU2)/R + gam11*R*ZU2 + Gam113*gam12*ZU3 +
  gam11*Gam123*ZU3 - cotth*gam13*ZU3 + Gam213*gam22*ZU3 + gam12*Gam223*ZU3 +
  gam23*Gam313*ZU3 + gam13*Gam323*ZU3 - (gam23*ZU3)/R
;

const auto
RZ13
=
-4*dphi3*ZD1 - 4*dphi1*ZD3 + gam11*Gam113*ZU1 + Gam111*gam13*ZU1 +
  gam12*Gam213*ZU1 + Gam211*gam23*ZU1 + gam13*Gam313*ZU1 +
  Gam311*gam33*ZU1 - (gam13*ZU1)/R + gam11*Gam123*ZU2 - cotth*gam13*ZU2 +
  Gam112*gam13*ZU2 + gam12*Gam223*ZU2 + Gam212*gam23*ZU2 +
  gam13*Gam323*ZU2 + Gam312*gam33*ZU2 - (gam23*ZU2)/R + Gam113*gam13*ZU3 +
  gam11*Gam133*ZU3 + Gam213*gam23*ZU3 + gam12*Gam233*ZU3 +
  Gam313*gam33*ZU3 + gam13*Gam333*ZU3 - (gam33*ZU3)/R +
  costh*gam12*sinth*ZU3 + gam11*R*Power(sinth,2)*ZU3
;

const auto
RZ22
=
2*(-4*dphi2*ZD2 + Gam112*gam12*ZU1 + Gam212*gam22*ZU1 + gam23*Gam312*ZU1 -
    (gam22*ZU1)/R + gam12*Gam122*ZU2 + gam22*Gam222*ZU2 + gam23*Gam322*ZU2 +
    gam12*R*ZU2 + gam12*Gam123*ZU3 + gam22*Gam223*ZU3 - cotth*gam23*ZU3 +
    gam23*Gam323*ZU3)
;

const auto
RZ23
=
-4*dphi3*ZD2 - 4*dphi2*ZD3 + Gam113*gam12*ZU1 + Gam112*gam13*ZU1 +
  Gam213*gam22*ZU1 + Gam212*gam23*ZU1 + gam23*Gam313*ZU1 +
  Gam312*gam33*ZU1 - (2*gam23*ZU1)/R + gam12*Gam123*ZU2 + Gam122*gam13*ZU2 +
  gam22*Gam223*ZU2 + Gam222*gam23*ZU2 + gam23*Gam323*ZU2 +
  Gam322*gam33*ZU2 + gam13*R*ZU2 + Gam123*gam13*ZU3 + gam12*Gam133*ZU3 +
  Gam223*gam23*ZU3 + gam22*Gam233*ZU3 + Gam323*gam33*ZU3 +
  gam23*Gam333*ZU3 + costh*gam22*sinth*ZU3 + gam12*R*Power(sinth,2)*ZU3 -
  cotth*(gam23*ZU2 + gam33*ZU3)
;

const auto
RZ33
=
2*(-4*dphi3*ZD3 + Gam113*gam13*ZU1 + Gam213*gam23*ZU1 + Gam313*gam33*ZU1 -
    (gam33*ZU1)/R + Gam123*gam13*ZU2 + Gam223*gam23*ZU2 - cotth*gam33*ZU2 +
    Gam323*gam33*ZU2 + gam13*Gam133*ZU3 + gam23*Gam233*ZU3 +
    gam33*Gam333*ZU3 + costh*gam23*sinth*ZU3 + gam13*R*Power(sinth,2)*ZU3)
;

const auto
Rb11
=
gamb11*hDLt11 + gamb12*hDLt12 + gamb13*hDLt13 +
  2*DGam111*DGamDDD111*invgamb11 + DGam211*DGamDDD112*invgamb11 +
  DGam311*DGamDDD113*invgamb11 + DGam211*DGamDDD211*invgamb11 +
  DGam311*DGamDDD311*invgamb11 - (hDhDgamb1111*invgamb11)/2. +
  2*DGam112*DGamDDD111*invgamb12 + 2*DGam111*DGamDDD112*invgamb12 +
  DGam212*DGamDDD112*invgamb12 + DGam312*DGamDDD113*invgamb12 +
  DGam211*DGamDDD122*invgamb12 + DGam311*DGamDDD123*invgamb12 +
  DGam212*DGamDDD211*invgamb12 + DGam211*DGamDDD212*invgamb12 +
  DGam312*DGamDDD311*invgamb12 + DGam311*DGamDDD312*invgamb12 -
  hDhDgamb1211*invgamb12 + 2*DGam113*DGamDDD111*invgamb13 +
  DGam213*DGamDDD112*invgamb13 + 2*DGam111*DGamDDD113*invgamb13 +
  DGam313*DGamDDD113*invgamb13 + DGam211*DGamDDD123*invgamb13 +
  DGam311*DGamDDD133*invgamb13 + DGam213*DGamDDD211*invgamb13 +
  DGam211*DGamDDD213*invgamb13 + DGam313*DGamDDD311*invgamb13 +
  DGam311*DGamDDD313*invgamb13 - hDhDgamb1311*invgamb13 +
  2*DGam112*DGamDDD112*invgamb22 + DGam212*DGamDDD122*invgamb22 +
  DGam312*DGamDDD123*invgamb22 + DGam212*DGamDDD212*invgamb22 +
  DGam312*DGamDDD312*invgamb22 - (hDhDgamb2211*invgamb22)/2. +
  2*DGam113*DGamDDD112*invgamb23 + 2*DGam112*DGamDDD113*invgamb23 +
  DGam213*DGamDDD122*invgamb23 + DGam212*DGamDDD123*invgamb23 +
  DGam313*DGamDDD123*invgamb23 + DGam312*DGamDDD133*invgamb23 +
  DGam213*DGamDDD212*invgamb23 + DGam212*DGamDDD213*invgamb23 +
  DGam313*DGamDDD312*invgamb23 + DGam312*DGamDDD313*invgamb23 -
  hDhDgamb2311*invgamb23 + 2*DGam113*DGamDDD113*invgamb33 +
  DGam213*DGamDDD123*invgamb33 + DGam313*DGamDDD133*invgamb33 +
  DGam213*DGamDDD213*invgamb33 + DGam313*DGamDDD313*invgamb33 -
  (hDhDgamb3311*invgamb33)/2. + RZ11 + DGamDDD111*trDGam1 +
  DGamDDD112*trDGam2 + DGamDDD113*trDGam3
;

const auto
Rb12
=
(gamb22*hDLt12 + gamb23*hDLt13 + gamb11*hDLt21 + gamb12*(hDLt11 + hDLt22) +
    gamb13*hDLt23 + DGam112*DGamDDD111*invgamb11 +
    2*DGam111*DGamDDD112*invgamb11 + DGam212*DGamDDD112*invgamb11 +
    DGam312*DGamDDD113*invgamb11 + DGam111*DGamDDD211*invgamb11 +
    3*DGam211*DGamDDD212*invgamb11 + DGam311*DGamDDD213*invgamb11 +
    2*DGam311*DGamDDD312*invgamb11 - hDhDgamb1112*invgamb11 +
    DGam122*DGamDDD111*invgamb12 + 3*DGam112*DGamDDD112*invgamb12 +
    DGam222*DGamDDD112*invgamb12 + DGam322*DGamDDD113*invgamb12 +
    2*DGam111*DGamDDD122*invgamb12 + DGam212*DGamDDD122*invgamb12 +
    DGam312*DGamDDD123*invgamb12 + DGam112*DGamDDD211*invgamb12 +
    DGam111*DGamDDD212*invgamb12 + 3*DGam212*DGamDDD212*invgamb12 +
    DGam312*DGamDDD213*invgamb12 + 3*DGam211*DGamDDD222*invgamb12 +
    DGam311*DGamDDD223*invgamb12 + 2*DGam312*DGamDDD312*invgamb12 +
    2*DGam311*DGamDDD322*invgamb12 - 2*hDhDgamb1212*invgamb12 +
    DGam123*DGamDDD111*invgamb13 + 2*DGam113*DGamDDD112*invgamb13 +
    DGam223*DGamDDD112*invgamb13 + DGam112*DGamDDD113*invgamb13 +
    DGam323*DGamDDD113*invgamb13 + 2*DGam111*DGamDDD123*invgamb13 +
    DGam212*DGamDDD123*invgamb13 + DGam312*DGamDDD133*invgamb13 +
    DGam113*DGamDDD211*invgamb13 + 3*DGam213*DGamDDD212*invgamb13 +
    DGam111*DGamDDD213*invgamb13 + DGam313*DGamDDD213*invgamb13 +
    3*DGam211*DGamDDD223*invgamb13 + DGam311*DGamDDD233*invgamb13 +
    2*DGam313*DGamDDD312*invgamb13 + 2*DGam311*DGamDDD323*invgamb13 -
    2*hDhDgamb1312*invgamb13 + DGam122*DGamDDD112*invgamb22 +
    2*DGam112*DGamDDD122*invgamb22 + DGam222*DGamDDD122*invgamb22 +
    DGam322*DGamDDD123*invgamb22 + DGam112*DGamDDD212*invgamb22 +
    3*DGam212*DGamDDD222*invgamb22 + DGam312*DGamDDD223*invgamb22 +
    2*DGam312*DGamDDD322*invgamb22 - hDhDgamb2212*invgamb22 +
    DGam123*DGamDDD112*invgamb23 + DGam122*DGamDDD113*invgamb23 +
    2*DGam113*DGamDDD122*invgamb23 + DGam223*DGamDDD122*invgamb23 +
    2*DGam112*DGamDDD123*invgamb23 + DGam222*DGamDDD123*invgamb23 +
    DGam323*DGamDDD123*invgamb23 + DGam322*DGamDDD133*invgamb23 +
    DGam113*DGamDDD212*invgamb23 + DGam112*DGamDDD213*invgamb23 +
    3*DGam213*DGamDDD222*invgamb23 + 3*DGam212*DGamDDD223*invgamb23 +
    DGam313*DGamDDD223*invgamb23 + DGam312*DGamDDD233*invgamb23 +
    2*DGam313*DGamDDD322*invgamb23 + 2*DGam312*DGamDDD323*invgamb23 -
    2*hDhDgamb2312*invgamb23 + DGam123*DGamDDD113*invgamb33 +
    2*DGam113*DGamDDD123*invgamb33 + DGam223*DGamDDD123*invgamb33 +
    DGam323*DGamDDD133*invgamb33 + DGam113*DGamDDD213*invgamb33 +
    3*DGam213*DGamDDD223*invgamb33 + DGam313*DGamDDD233*invgamb33 +
    2*DGam313*DGamDDD323*invgamb33 - hDhDgamb3312*invgamb33 + 2*RZ12 +
    DGamDDD112*trDGam1 + DGamDDD211*trDGam1 + DGamDDD122*trDGam2 +
    DGamDDD212*trDGam2 + DGamDDD123*trDGam3 + DGamDDD213*trDGam3)/2.
;

const auto
Rb13
=
(gamb23*hDLt12 + gamb33*hDLt13 + gamb11*hDLt31 + gamb12*hDLt32 +
    gamb13*(hDLt11 + hDLt33) + DGam113*DGamDDD111*invgamb11 +
    DGam213*DGamDDD112*invgamb11 + 2*DGam111*DGamDDD113*invgamb11 +
    DGam313*DGamDDD113*invgamb11 + 2*DGam211*DGamDDD213*invgamb11 +
    DGam111*DGamDDD311*invgamb11 + DGam211*DGamDDD312*invgamb11 +
    3*DGam311*DGamDDD313*invgamb11 - hDhDgamb1113*invgamb11 +
    DGam123*DGamDDD111*invgamb12 + DGam113*DGamDDD112*invgamb12 +
    DGam223*DGamDDD112*invgamb12 + 2*DGam112*DGamDDD113*invgamb12 +
    DGam323*DGamDDD113*invgamb12 + DGam213*DGamDDD122*invgamb12 +
    2*DGam111*DGamDDD123*invgamb12 + DGam313*DGamDDD123*invgamb12 +
    2*DGam212*DGamDDD213*invgamb12 + 2*DGam211*DGamDDD223*invgamb12 +
    DGam112*DGamDDD311*invgamb12 + DGam111*DGamDDD312*invgamb12 +
    DGam212*DGamDDD312*invgamb12 + 3*DGam312*DGamDDD313*invgamb12 +
    DGam211*DGamDDD322*invgamb12 + 3*DGam311*DGamDDD323*invgamb12 -
    2*hDhDgamb1213*invgamb12 + DGam133*DGamDDD111*invgamb13 +
    DGam233*DGamDDD112*invgamb13 + 3*DGam113*DGamDDD113*invgamb13 +
    DGam333*DGamDDD113*invgamb13 + DGam213*DGamDDD123*invgamb13 +
    2*DGam111*DGamDDD133*invgamb13 + DGam313*DGamDDD133*invgamb13 +
    2*DGam213*DGamDDD213*invgamb13 + 2*DGam211*DGamDDD233*invgamb13 +
    DGam113*DGamDDD311*invgamb13 + DGam213*DGamDDD312*invgamb13 +
    DGam111*DGamDDD313*invgamb13 + 3*DGam313*DGamDDD313*invgamb13 +
    DGam211*DGamDDD323*invgamb13 + 3*DGam311*DGamDDD333*invgamb13 -
    2*hDhDgamb1313*invgamb13 + DGam123*DGamDDD112*invgamb22 +
    DGam223*DGamDDD122*invgamb22 + 2*DGam112*DGamDDD123*invgamb22 +
    DGam323*DGamDDD123*invgamb22 + 2*DGam212*DGamDDD223*invgamb22 +
    DGam112*DGamDDD312*invgamb22 + DGam212*DGamDDD322*invgamb22 +
    3*DGam312*DGamDDD323*invgamb22 - hDhDgamb2213*invgamb22 +
    DGam133*DGamDDD112*invgamb23 + DGam123*DGamDDD113*invgamb23 +
    DGam233*DGamDDD122*invgamb23 + 2*DGam113*DGamDDD123*invgamb23 +
    DGam223*DGamDDD123*invgamb23 + DGam333*DGamDDD123*invgamb23 +
    2*DGam112*DGamDDD133*invgamb23 + DGam323*DGamDDD133*invgamb23 +
    2*DGam213*DGamDDD223*invgamb23 + 2*DGam212*DGamDDD233*invgamb23 +
    DGam113*DGamDDD312*invgamb23 + DGam112*DGamDDD313*invgamb23 +
    DGam213*DGamDDD322*invgamb23 + DGam212*DGamDDD323*invgamb23 +
    3*DGam313*DGamDDD323*invgamb23 + 3*DGam312*DGamDDD333*invgamb23 -
    2*hDhDgamb2313*invgamb23 + DGam133*DGamDDD113*invgamb33 +
    DGam233*DGamDDD123*invgamb33 + 2*DGam113*DGamDDD133*invgamb33 +
    DGam333*DGamDDD133*invgamb33 + 2*DGam213*DGamDDD233*invgamb33 +
    DGam113*DGamDDD313*invgamb33 + DGam213*DGamDDD323*invgamb33 +
    3*DGam313*DGamDDD333*invgamb33 - hDhDgamb3313*invgamb33 + 2*RZ13 +
    DGamDDD113*trDGam1 + DGamDDD311*trDGam1 + DGamDDD123*trDGam2 +
    DGamDDD312*trDGam2 + DGamDDD133*trDGam3 + DGamDDD313*trDGam3)/2.
;

const auto
Rb22
=
gamb12*hDLt21 + gamb22*hDLt22 + gamb23*hDLt23 +
  DGam112*DGamDDD112*invgamb11 + DGam112*DGamDDD211*invgamb11 +
  2*DGam212*DGamDDD212*invgamb11 + DGam312*DGamDDD213*invgamb11 +
  DGam312*DGamDDD312*invgamb11 - (hDhDgamb1122*invgamb11)/2. +
  DGam122*DGamDDD112*invgamb12 + DGam112*DGamDDD122*invgamb12 +
  DGam122*DGamDDD211*invgamb12 + DGam112*DGamDDD212*invgamb12 +
  2*DGam222*DGamDDD212*invgamb12 + DGam322*DGamDDD213*invgamb12 +
  2*DGam212*DGamDDD222*invgamb12 + DGam312*DGamDDD223*invgamb12 +
  DGam322*DGamDDD312*invgamb12 + DGam312*DGamDDD322*invgamb12 -
  hDhDgamb1222*invgamb12 + DGam123*DGamDDD112*invgamb13 +
  DGam112*DGamDDD123*invgamb13 + DGam123*DGamDDD211*invgamb13 +
  2*DGam223*DGamDDD212*invgamb13 + DGam112*DGamDDD213*invgamb13 +
  DGam323*DGamDDD213*invgamb13 + 2*DGam212*DGamDDD223*invgamb13 +
  DGam312*DGamDDD233*invgamb13 + DGam323*DGamDDD312*invgamb13 +
  DGam312*DGamDDD323*invgamb13 - hDhDgamb1322*invgamb13 +
  DGam122*DGamDDD122*invgamb22 + DGam122*DGamDDD212*invgamb22 +
  2*DGam222*DGamDDD222*invgamb22 + DGam322*DGamDDD223*invgamb22 +
  DGam322*DGamDDD322*invgamb22 - (hDhDgamb2222*invgamb22)/2. +
  DGam123*DGamDDD122*invgamb23 + DGam122*DGamDDD123*invgamb23 +
  DGam123*DGamDDD212*invgamb23 + DGam122*DGamDDD213*invgamb23 +
  2*DGam223*DGamDDD222*invgamb23 + 2*DGam222*DGamDDD223*invgamb23 +
  DGam323*DGamDDD223*invgamb23 + DGam322*DGamDDD233*invgamb23 +
  DGam323*DGamDDD322*invgamb23 + DGam322*DGamDDD323*invgamb23 -
  hDhDgamb2322*invgamb23 + DGam123*DGamDDD123*invgamb33 +
  DGam123*DGamDDD213*invgamb33 + 2*DGam223*DGamDDD223*invgamb33 +
  DGam323*DGamDDD233*invgamb33 + DGam323*DGamDDD323*invgamb33 -
  (hDhDgamb3322*invgamb33)/2. + RZ22 + DGamDDD212*trDGam1 +
  DGamDDD222*trDGam2 + DGamDDD223*trDGam3
;

const auto
Rb23
=
(gamb13*hDLt21 + gamb33*hDLt23 + gamb12*hDLt31 + gamb22*hDLt32 +
    gamb23*(hDLt22 + hDLt33) + 2*DGam112*DGamDDD113*invgamb11 +
    DGam113*DGamDDD211*invgamb11 + DGam213*DGamDDD212*invgamb11 +
    2*DGam212*DGamDDD213*invgamb11 + DGam313*DGamDDD213*invgamb11 +
    DGam112*DGamDDD311*invgamb11 + DGam212*DGamDDD312*invgamb11 +
    3*DGam312*DGamDDD313*invgamb11 - hDhDgamb1123*invgamb11 +
    2*DGam122*DGamDDD113*invgamb12 + 2*DGam112*DGamDDD123*invgamb12 +
    DGam123*DGamDDD211*invgamb12 + DGam113*DGamDDD212*invgamb12 +
    DGam223*DGamDDD212*invgamb12 + 2*DGam222*DGamDDD213*invgamb12 +
    DGam323*DGamDDD213*invgamb12 + DGam213*DGamDDD222*invgamb12 +
    2*DGam212*DGamDDD223*invgamb12 + DGam313*DGamDDD223*invgamb12 +
    DGam122*DGamDDD311*invgamb12 + DGam112*DGamDDD312*invgamb12 +
    DGam222*DGamDDD312*invgamb12 + 3*DGam322*DGamDDD313*invgamb12 +
    DGam212*DGamDDD322*invgamb12 + 3*DGam312*DGamDDD323*invgamb12 -
    2*hDhDgamb1223*invgamb12 + 2*DGam123*DGamDDD113*invgamb13 +
    2*DGam112*DGamDDD133*invgamb13 + DGam133*DGamDDD211*invgamb13 +
    DGam233*DGamDDD212*invgamb13 + DGam113*DGamDDD213*invgamb13 +
    2*DGam223*DGamDDD213*invgamb13 + DGam333*DGamDDD213*invgamb13 +
    DGam213*DGamDDD223*invgamb13 + 2*DGam212*DGamDDD233*invgamb13 +
    DGam313*DGamDDD233*invgamb13 + DGam123*DGamDDD311*invgamb13 +
    DGam223*DGamDDD312*invgamb13 + DGam112*DGamDDD313*invgamb13 +
    3*DGam323*DGamDDD313*invgamb13 + DGam212*DGamDDD323*invgamb13 +
    3*DGam312*DGamDDD333*invgamb13 - 2*hDhDgamb1323*invgamb13 +
    2*DGam122*DGamDDD123*invgamb22 + DGam123*DGamDDD212*invgamb22 +
    DGam223*DGamDDD222*invgamb22 + 2*DGam222*DGamDDD223*invgamb22 +
    DGam323*DGamDDD223*invgamb22 + DGam122*DGamDDD312*invgamb22 +
    DGam222*DGamDDD322*invgamb22 + 3*DGam322*DGamDDD323*invgamb22 -
    hDhDgamb2223*invgamb22 + 2*DGam123*DGamDDD123*invgamb23 +
    2*DGam122*DGamDDD133*invgamb23 + DGam133*DGamDDD212*invgamb23 +
    DGam123*DGamDDD213*invgamb23 + DGam233*DGamDDD222*invgamb23 +
    3*DGam223*DGamDDD223*invgamb23 + DGam333*DGamDDD223*invgamb23 +
    2*DGam222*DGamDDD233*invgamb23 + DGam323*DGamDDD233*invgamb23 +
    DGam123*DGamDDD312*invgamb23 + DGam122*DGamDDD313*invgamb23 +
    DGam223*DGamDDD322*invgamb23 + DGam222*DGamDDD323*invgamb23 +
    3*DGam323*DGamDDD323*invgamb23 + 3*DGam322*DGamDDD333*invgamb23 -
    2*hDhDgamb2323*invgamb23 + 2*DGam123*DGamDDD133*invgamb33 +
    DGam133*DGamDDD213*invgamb33 + DGam233*DGamDDD223*invgamb33 +
    2*DGam223*DGamDDD233*invgamb33 + DGam333*DGamDDD233*invgamb33 +
    DGam123*DGamDDD313*invgamb33 + DGam223*DGamDDD323*invgamb33 +
    3*DGam323*DGamDDD333*invgamb33 - hDhDgamb3323*invgamb33 + 2*RZ23 +
    DGamDDD213*trDGam1 + DGamDDD312*trDGam1 + DGamDDD223*trDGam2 +
    DGamDDD322*trDGam2 + DGamDDD233*trDGam3 + DGamDDD323*trDGam3)/2.
;

const auto
Rb33
=
gamb13*hDLt31 + gamb23*hDLt32 + gamb33*hDLt33 +
  DGam113*DGamDDD113*invgamb11 + DGam213*DGamDDD213*invgamb11 +
  DGam113*DGamDDD311*invgamb11 + DGam213*DGamDDD312*invgamb11 +
  2*DGam313*DGamDDD313*invgamb11 - (hDhDgamb1133*invgamb11)/2. +
  DGam123*DGamDDD113*invgamb12 + DGam113*DGamDDD123*invgamb12 +
  DGam223*DGamDDD213*invgamb12 + DGam213*DGamDDD223*invgamb12 +
  DGam123*DGamDDD311*invgamb12 + DGam113*DGamDDD312*invgamb12 +
  DGam223*DGamDDD312*invgamb12 + 2*DGam323*DGamDDD313*invgamb12 +
  DGam213*DGamDDD322*invgamb12 + 2*DGam313*DGamDDD323*invgamb12 -
  hDhDgamb1233*invgamb12 + DGam133*DGamDDD113*invgamb13 +
  DGam113*DGamDDD133*invgamb13 + DGam233*DGamDDD213*invgamb13 +
  DGam213*DGamDDD233*invgamb13 + DGam133*DGamDDD311*invgamb13 +
  DGam233*DGamDDD312*invgamb13 + DGam113*DGamDDD313*invgamb13 +
  2*DGam333*DGamDDD313*invgamb13 + DGam213*DGamDDD323*invgamb13 +
  2*DGam313*DGamDDD333*invgamb13 - hDhDgamb1333*invgamb13 +
  DGam123*DGamDDD123*invgamb22 + DGam223*DGamDDD223*invgamb22 +
  DGam123*DGamDDD312*invgamb22 + DGam223*DGamDDD322*invgamb22 +
  2*DGam323*DGamDDD323*invgamb22 - (hDhDgamb2233*invgamb22)/2. +
  DGam133*DGamDDD123*invgamb23 + DGam123*DGamDDD133*invgamb23 +
  DGam233*DGamDDD223*invgamb23 + DGam223*DGamDDD233*invgamb23 +
  DGam133*DGamDDD312*invgamb23 + DGam123*DGamDDD313*invgamb23 +
  DGam233*DGamDDD322*invgamb23 + DGam223*DGamDDD323*invgamb23 +
  2*DGam333*DGamDDD323*invgamb23 + 2*DGam323*DGamDDD333*invgamb23 -
  hDhDgamb2333*invgamb23 + DGam133*DGamDDD133*invgamb33 +
  DGam233*DGamDDD233*invgamb33 + DGam133*DGamDDD313*invgamb33 +
  DGam233*DGamDDD323*invgamb33 + 2*DGam333*DGamDDD333*invgamb33 -
  (hDhDgamb3333*invgamb33)/2. + RZ33 + DGamDDD313*trDGam1 +
  DGamDDD323*trDGam2 + DGamDDD333*trDGam3
;

const auto
trRb
=
invgamb11*Rb11 + 2*invgamb12*Rb12 + 2*invgamb13*Rb13 + invgamb22*Rb22 +
  2*invgamb23*Rb23 + invgamb33*Rb33
;

const auto
RbTF11
=
Rb11 - (gamb11*trRb)/3.
;

const auto
RbTF12
=
Rb12 - (gamb12*trRb)/3.
;

const auto
RbTF13
=
Rb13 - (gamb13*trRb)/3.
;

const auto
RbTF22
=
Rb22 - (gamb22*trRb)/3.
;

const auto
RbTF23
=
Rb23 - (gamb23*trRb)/3.
;

const auto
RbTF33
=
Rb33 - (gamb33*trRb)/3.
;

const auto
Rphi11
=
4*dalpha1*dphi1 - 2*(bDbDphi11 - 2*Power(dphi1,2))*alpha[ijk]
;

const auto
Rphi12
=
2*(dalpha2*dphi1 + dalpha1*dphi2 - (bDbDphi12 - 2*dphi1*dphi2)*alpha[ijk])
;

const auto
Rphi13
=
2*(dalpha3*dphi1 + dalpha1*dphi3 - (bDbDphi13 - 2*dphi1*dphi3)*alpha[ijk])
;

const auto
Rphi22
=
4*dalpha2*dphi2 - 2*(bDbDphi22 - 2*Power(dphi2,2))*alpha[ijk]
;

const auto
Rphi23
=
2*(dalpha3*dphi2 + dalpha2*dphi3 - (bDbDphi23 - 2*dphi2*dphi3)*alpha[ijk])
;

const auto
Rphi33
=
4*dalpha3*dphi3 - 2*(bDbDphi33 - 2*Power(dphi3,2))*alpha[ijk]
;

const auto
RphiTF11
=
((3 - gamb11*invgamb11)*Rphi11 -
    gamb11*(2*invgamb12*Rphi12 + 2*invgamb13*Rphi13 + invgamb22*Rphi22 +
       2*invgamb23*Rphi23 + invgamb33*Rphi33))/3.
;

const auto
RphiTF12
=
Rphi12 - (gamb12*(invgamb11*Rphi11 + 2*invgamb12*Rphi12 +
       2*invgamb13*Rphi13 + invgamb22*Rphi22 + 2*invgamb23*Rphi23 +
       invgamb33*Rphi33))/3.
;

const auto
RphiTF13
=
Rphi13 - (gamb13*(invgamb11*Rphi11 + 2*invgamb12*Rphi12 +
       2*invgamb13*Rphi13 + invgamb22*Rphi22 + 2*invgamb23*Rphi23 +
       invgamb33*Rphi33))/3.
;

const auto
RphiTF22
=
Rphi22 - (gamb22*(invgamb11*Rphi11 + 2*invgamb12*Rphi12 +
       2*invgamb13*Rphi13 + invgamb22*Rphi22 + 2*invgamb23*Rphi23 +
       invgamb33*Rphi33))/3.
;

const auto
RphiTF23
=
Rphi23 - (gamb23*(invgamb11*Rphi11 + 2*invgamb12*Rphi12 +
       2*invgamb13*Rphi13 + invgamb22*Rphi22 + 2*invgamb23*Rphi23 +
       invgamb33*Rphi33))/3.
;

const auto
RphiTF33
=
Rphi33 - (gamb33*(invgamb11*Rphi11 + 2*invgamb12*Rphi12 +
       2*invgamb13*Rphi13 + invgamb22*Rphi22 + 2*invgamb23*Rphi23 +
       invgamb33*Rphi33))/3.
;

const auto
Ralpha11
=
-bDbDalpha11
;

const auto
Ralpha12
=
-bDbDalpha12
;

const auto
Ralpha13
=
-bDbDalpha13
;

const auto
Ralpha22
=
-bDbDalpha22
;

const auto
Ralpha23
=
-bDbDalpha23
;

const auto
Ralpha33
=
-bDbDalpha33
;

const auto
RalphaTF11
=
((3 - gamb11*invgamb11)*Ralpha11 -
    gamb11*(2*invgamb12*Ralpha12 + 2*invgamb13*Ralpha13 +
       invgamb22*Ralpha22 + 2*invgamb23*Ralpha23 + invgamb33*Ralpha33))/3.
;

const auto
RalphaTF12
=
Ralpha12 - (gamb12*(invgamb11*Ralpha11 + 2*invgamb12*Ralpha12 +
       2*invgamb13*Ralpha13 + invgamb22*Ralpha22 + 2*invgamb23*Ralpha23 +
       invgamb33*Ralpha33))/3.
;

const auto
RalphaTF13
=
Ralpha13 - (gamb13*(invgamb11*Ralpha11 + 2*invgamb12*Ralpha12 +
       2*invgamb13*Ralpha13 + invgamb22*Ralpha22 + 2*invgamb23*Ralpha23 +
       invgamb33*Ralpha33))/3.
;

const auto
RalphaTF22
=
Ralpha22 - (gamb22*(invgamb11*Ralpha11 + 2*invgamb12*Ralpha12 +
       2*invgamb13*Ralpha13 + invgamb22*Ralpha22 + 2*invgamb23*Ralpha23 +
       invgamb33*Ralpha33))/3.
;

const auto
RalphaTF23
=
Ralpha23 - (gamb23*(invgamb11*Ralpha11 + 2*invgamb12*Ralpha12 +
       2*invgamb13*Ralpha13 + invgamb22*Ralpha22 + 2*invgamb23*Ralpha23 +
       invgamb33*Ralpha33))/3.
;

const auto
RalphaTF33
=
Ralpha33 - (gamb33*(invgamb11*Ralpha11 + 2*invgamb12*Ralpha12 +
       2*invgamb13*Ralpha13 + invgamb22*Ralpha22 + 2*invgamb23*Ralpha23 +
       invgamb33*Ralpha33))/3.
;


const auto
rho
=
(Power(beta1,2)*eT11 + Power(beta2,2)*eT22 + 2*beta2*beta3*eT23 +
    Power(beta3,2)*eT33 + 2*beta1*(beta2*eT12 + beta3*eT13 - eTt1) -
    2*beta2*eTt2 - 2*beta3*eTt3 + eTtt)/Power(alpha[ijk],2)
;

const auto
Sm1
=
(beta1*eT11 + beta2*eT12 + beta3*eT13 - eTt1)/alpha[ijk]
;

const auto
Sm2
=
(beta1*eT12 + beta2*eT22 + beta3*eT23 - eTt2)/alpha[ijk]
;

const auto
Sm3
=
(beta1*eT13 + beta2*eT23 + beta3*eT33 - eTt3)/alpha[ijk]
;

const auto
Ss11
=
eT11
;

const auto
Ss12
=
eT12
;

const auto
Ss13
=
eT13
;

const auto
Ss22
=
eT22
;

const auto
Ss23
=
eT23
;

const auto
Ss33
=
eT33
;

const auto
trSs
=
invgam11*Ss11 + 2*invgam12*Ss12 + 2*invgam13*Ss13 + invgam22*Ss22 +
  2*invgam23*Ss23 + invgam33*Ss33
;


const auto
Lbetaphi
=
beta1*dphi1 + beta2*dphi2 + beta3*dphi3
;

const auto
LbetatrK
=
beta1*dtrK1 + beta2*dtrK2 + beta3*dtrK3
;

const auto
LbetaTheta
=
beta1*dTheta1 + beta2*dTheta2 + beta3*dTheta3
;

const auto
Lbetaalpha
=
beta1*dalpha1 + beta2*dalpha2 + beta3*dalpha3
;

const auto
Lbetagamb11
=
beta1*dgamb111 + beta2*dgamb211 + beta3*dgamb311 + 2*dbeta11*gamb11 +
  2*dbeta12*gamb12 + 2*dbeta13*gamb13
;

const auto
Lbetagamb12
=
beta1*dgamb112 + beta2*dgamb212 + beta3*dgamb312 + dbeta21*gamb11 +
  dbeta11*gamb12 + dbeta22*gamb12 + dbeta23*gamb13 + dbeta12*gamb22 +
  dbeta13*gamb23
;

const auto
Lbetagamb13
=
beta1*dgamb113 + beta2*dgamb213 + beta3*dgamb313 + dbeta31*gamb11 +
  dbeta32*gamb12 + dbeta11*gamb13 + dbeta33*gamb13 + dbeta12*gamb23 +
  dbeta13*gamb33
;

const auto
Lbetagamb22
=
beta1*dgamb122 + beta2*dgamb222 + beta3*dgamb322 + 2*dbeta21*gamb12 +
  2*dbeta22*gamb22 + 2*dbeta23*gamb23
;

const auto
Lbetagamb23
=
beta1*dgamb123 + beta2*dgamb223 + beta3*dgamb323 + dbeta31*gamb12 +
  dbeta21*gamb13 + dbeta32*gamb22 + dbeta22*gamb23 + dbeta33*gamb23 +
  dbeta23*gamb33
;

const auto
Lbetagamb33
=
beta1*dgamb133 + beta2*dgamb233 + beta3*dgamb333 + 2*dbeta31*gamb13 +
  2*dbeta32*gamb23 + 2*dbeta33*gamb33
;

const auto
LbetaexAb11
=
beta1*dexAb111 + beta2*dexAb211 + beta3*dexAb311 + 2*dbeta11*exAb11 +
  2*dbeta12*exAb12 + 2*dbeta13*exAb13
;

const auto
LbetaexAb12
=
beta1*dexAb112 + beta2*dexAb212 + beta3*dexAb312 + dbeta21*exAb11 +
  dbeta11*exAb12 + dbeta22*exAb12 + dbeta23*exAb13 + dbeta12*exAb22 +
  dbeta13*exAb23
;

const auto
LbetaexAb13
=
beta1*dexAb113 + beta2*dexAb213 + beta3*dexAb313 + dbeta31*exAb11 +
  dbeta32*exAb12 + dbeta11*exAb13 + dbeta33*exAb13 + dbeta12*exAb23 +
  dbeta13*exAb33
;

const auto
LbetaexAb22
=
beta1*dexAb122 + beta2*dexAb222 + beta3*dexAb322 + 2*dbeta21*exAb12 +
  2*dbeta22*exAb22 + 2*dbeta23*exAb23
;

const auto
LbetaexAb23
=
beta1*dexAb123 + beta2*dexAb223 + beta3*dexAb323 + dbeta31*exAb12 +
  dbeta21*exAb13 + dbeta32*exAb22 + dbeta22*exAb23 + dbeta33*exAb23 +
  dbeta23*exAb33
;

const auto
LbetaexAb33
=
beta1*dexAb133 + beta2*dexAb233 + beta3*dexAb333 + 2*dbeta31*exAb13 +
  2*dbeta32*exAb23 + 2*dbeta33*exAb33
;

const auto
LbetaLt1
=
beta1*dLt11 + beta2*dLt21 + beta3*dLt31 - dbeta11*Lt1 - dbeta21*Lt2 -
  dbeta31*Lt3
;

const auto
LbetaLt2
=
beta1*dLt12 + beta2*dLt22 + beta3*dLt32 - dbeta12*Lt1 - dbeta22*Lt2 -
  dbeta32*Lt3
;

const auto
LbetaLt3
=
beta1*dLt13 + beta2*dLt23 + beta3*dLt33 - dbeta13*Lt1 - dbeta23*Lt2 -
  dbeta33*Lt3
;

const auto
LbetaB1
=
beta1*dB11 + beta2*dB21 + beta3*dB31 + B1*dbeta11 + B2*dbeta21 + B3*dbeta31
;

const auto
LbetaB2
=
beta1*dB12 + beta2*dB22 + beta3*dB32 + B1*dbeta12 + B2*dbeta22 + B3*dbeta32
;

const auto
LbetaB3
=
beta1*dB13 + beta2*dB23 + beta3*dB33 + B1*dbeta13 + B2*dbeta23 + B3*dbeta33
;


dtphi[ijk]
=
(6*Lbetaphi + trbDbeta - alpha[ijk]*trK[ijk])/6.
;

dttrK[ijk]
=
LbetatrK - 2*dalpha1*dphi1*invgam11*psim4 - 2*dalpha2*dphi1*invgam12*psim4 -
  2*dalpha1*dphi2*invgam12*psim4 - 2*dalpha3*dphi1*invgam13*psim4 -
  2*dalpha1*dphi3*invgam13*psim4 - 2*dalpha2*dphi2*invgam22*psim4 -
  2*dalpha3*dphi2*invgam23*psim4 - 2*dalpha2*dphi3*invgam23*psim4 -
  2*dalpha3*dphi3*invgam33*psim4 - psim4*trbDbDalpha -
  3*ckappa1*(1 + ckappa2)*Theta[ijk] +
  alpha[ijk]*(-12*cpi*rho - 8*psim4*trbDbDphi - 8*psim4*trbDphibDphi +
     psim4*trRb + 4*cpi*trSs - 2*Theta[ijk]*trK[ijk] + Power(trK[ijk],2))
;

dtTheta[ijk]
=
LbetaTheta - dalpha1*ZU1 - dalpha2*ZU2 - dalpha3*ZU3 -
  ckappa1*(2 + ckappa2)*Theta[ijk] -
  (alpha[ijk]*(3*(exAb11*exAbUU11 + 2*exAb12*exAbUU12 +
          2*exAb13*exAbUU13 + exAb22*exAbUU22 + 2*exAb23*exAbUU23 +
          exAb33*exAbUU33 + 16*cpi*rho + 8*psim4*trbDbDphi +
          8*psim4*trbDphibDphi - psim4*trRb) + 6*Theta[ijk]*trK[ijk] -
       2*Power(trK[ijk],2)))/6.
;

dtalpha[ijk]
=
Lbetaalpha + alpha[ijk]*(4*Theta[ijk] - 2*trK[ijk])
;

const auto
dteps11
=
Lbetagamb11 - (2*gamb11*trbDbeta)/3. +
  (-2*exAb11 + (2*gamb11*trexAb)/3.)*alpha[ijk]
;

const auto
dteps12
=
Lbetagamb12 - (2*gamb12*trbDbeta)/3. +
  (-2*exAb12 + (2*gamb12*trexAb)/3.)*alpha[ijk]
;

const auto
dteps13
=
Lbetagamb13 - (2*gamb13*trbDbeta)/3. +
  (-2*exAb13 + (2*gamb13*trexAb)/3.)*alpha[ijk]
;

const auto
dteps22
=
Lbetagamb22 - (2*gamb22*trbDbeta)/3. +
  (-2*exAb22 + (2*gamb22*trexAb)/3.)*alpha[ijk]
;

const auto
dteps23
=
Lbetagamb23 - (2*gamb23*trbDbeta)/3. +
  (-2*exAb23 + (2*gamb23*trexAb)/3.)*alpha[ijk]
;

const auto
dteps33
=
Lbetagamb33 - (2*gamb33*trbDbeta)/3. +
  (-2*exAb33 + (2*gamb33*trexAb)/3.)*alpha[ijk]
;

const auto
dtexAb11
=
LbetaexAb11 + psim4*RalphaTF11 + psim4*RphiTF11 - (2*exAb11*trbDbeta)/3. +
  (alpha[ijk]*(-6*Power(exAb11,2)*invgamb11 - 12*exAb11*exAb12*invgamb12 -
       12*exAb11*exAb13*invgamb13 - 6*Power(exAb12,2)*invgamb22 -
       12*exAb12*exAb13*invgamb23 - 6*Power(exAb13,2)*invgamb33 +
       3*psim4*RbTF11 - 24*cpi*psim4*Ss11 +
       8*cpi*gamb11*invgamb11*psim4*Ss11 +
       16*cpi*gamb11*invgamb12*psim4*Ss12 +
       16*cpi*gamb11*invgamb13*psim4*Ss13 +
       8*cpi*gamb11*invgamb22*psim4*Ss22 +
       16*cpi*gamb11*invgamb23*psim4*Ss23 +
       8*cpi*gamb11*invgamb33*psim4*Ss33 - 6*exAb11*Theta[ijk] +
       3*exAb11*trK[ijk]))/3.
;

const auto
dtexAb12
=
LbetaexAb12 + psim4*RalphaTF12 + psim4*RphiTF12 - (2*exAb12*trbDbeta)/3. -
  (alpha[ijk]*(6*exAb11*exAb12*invgamb11 + 6*Power(exAb12,2)*invgamb12 +
       6*exAb11*exAb22*invgamb12 + 6*exAb12*exAb13*invgamb13 +
       6*exAb11*exAb23*invgamb13 + 6*exAb12*exAb22*invgamb22 +
       6*exAb13*exAb22*invgamb23 + 6*exAb12*exAb23*invgamb23 +
       6*exAb13*exAb23*invgamb33 - 3*psim4*RbTF12 -
       8*cpi*gamb12*invgamb11*psim4*Ss11 + 24*cpi*psim4*Ss12 -
       16*cpi*gamb12*invgamb12*psim4*Ss12 -
       16*cpi*gamb12*invgamb13*psim4*Ss13 -
       8*cpi*gamb12*invgamb22*psim4*Ss22 -
       16*cpi*gamb12*invgamb23*psim4*Ss23 -
       8*cpi*gamb12*invgamb33*psim4*Ss33 + 6*exAb12*Theta[ijk] -
       3*exAb12*trK[ijk]))/3.
;

const auto
dtexAb13
=
LbetaexAb13 + psim4*RalphaTF13 + psim4*RphiTF13 - (2*exAb13*trbDbeta)/3. -
  (alpha[ijk]*(6*exAb11*exAb13*invgamb11 + 6*exAb12*exAb13*invgamb12 +
       6*exAb11*exAb23*invgamb12 + 6*Power(exAb13,2)*invgamb13 +
       6*exAb11*exAb33*invgamb13 + 6*exAb12*exAb23*invgamb22 +
       6*exAb13*exAb23*invgamb23 + 6*exAb12*exAb33*invgamb23 +
       6*exAb13*exAb33*invgamb33 - 3*psim4*RbTF13 -
       8*cpi*gamb13*invgamb11*psim4*Ss11 -
       16*cpi*gamb13*invgamb12*psim4*Ss12 + 24*cpi*psim4*Ss13 -
       16*cpi*gamb13*invgamb13*psim4*Ss13 -
       8*cpi*gamb13*invgamb22*psim4*Ss22 -
       16*cpi*gamb13*invgamb23*psim4*Ss23 -
       8*cpi*gamb13*invgamb33*psim4*Ss33 + 6*exAb13*Theta[ijk] -
       3*exAb13*trK[ijk]))/3.
;

const auto
dtexAb22
=
LbetaexAb22 + psim4*RalphaTF22 + psim4*RphiTF22 - (2*exAb22*trbDbeta)/3. +
  (alpha[ijk]*(-6*Power(exAb12,2)*invgamb11 - 12*exAb12*exAb22*invgamb12 -
       12*exAb12*exAb23*invgamb13 - 6*Power(exAb22,2)*invgamb22 -
       12*exAb22*exAb23*invgamb23 - 6*Power(exAb23,2)*invgamb33 +
       3*psim4*RbTF22 + 8*cpi*gamb22*invgamb11*psim4*Ss11 +
       16*cpi*gamb22*invgamb12*psim4*Ss12 +
       16*cpi*gamb22*invgamb13*psim4*Ss13 - 24*cpi*psim4*Ss22 +
       8*cpi*gamb22*invgamb22*psim4*Ss22 +
       16*cpi*gamb22*invgamb23*psim4*Ss23 +
       8*cpi*gamb22*invgamb33*psim4*Ss33 - 6*exAb22*Theta[ijk] +
       3*exAb22*trK[ijk]))/3.
;

const auto
dtexAb23
=
LbetaexAb23 + psim4*RalphaTF23 + psim4*RphiTF23 - (2*exAb23*trbDbeta)/3. -
  (alpha[ijk]*(6*exAb12*exAb13*invgamb11 + 6*exAb13*exAb22*invgamb12 +
       6*exAb12*exAb23*invgamb12 + 6*exAb13*exAb23*invgamb13 +
       6*exAb12*exAb33*invgamb13 + 6*exAb22*exAb23*invgamb22 +
       6*Power(exAb23,2)*invgamb23 + 6*exAb22*exAb33*invgamb23 +
       6*exAb23*exAb33*invgamb33 - 3*psim4*RbTF23 -
       8*cpi*gamb23*invgamb11*psim4*Ss11 -
       16*cpi*gamb23*invgamb12*psim4*Ss12 -
       16*cpi*gamb23*invgamb13*psim4*Ss13 -
       8*cpi*gamb23*invgamb22*psim4*Ss22 + 24*cpi*psim4*Ss23 -
       16*cpi*gamb23*invgamb23*psim4*Ss23 -
       8*cpi*gamb23*invgamb33*psim4*Ss33 + 6*exAb23*Theta[ijk] -
       3*exAb23*trK[ijk]))/3.
;

const auto
dtexAb33
=
LbetaexAb33 + psim4*RalphaTF33 + psim4*RphiTF33 - (2*exAb33*trbDbeta)/3. +
  (alpha[ijk]*(-6*Power(exAb13,2)*invgamb11 - 12*exAb13*exAb23*invgamb12 -
       12*exAb13*exAb33*invgamb13 - 6*Power(exAb23,2)*invgamb22 -
       12*exAb23*exAb33*invgamb23 - 6*Power(exAb33,2)*invgamb33 +
       3*psim4*RbTF33 + 8*cpi*gamb33*invgamb11*psim4*Ss11 +
       16*cpi*gamb33*invgamb12*psim4*Ss12 +
       16*cpi*gamb33*invgamb13*psim4*Ss13 +
       8*cpi*gamb33*invgamb22*psim4*Ss22 +
       16*cpi*gamb33*invgamb23*psim4*Ss23 - 24*cpi*psim4*Ss33 +
       8*cpi*gamb33*invgamb33*psim4*Ss33 - 6*exAb33*Theta[ijk] +
       3*exAb33*trK[ijk]))/3.
;

const auto
dtLt1
=
(-6*dalpha1*exAbUU11 - 6*dalpha2*exAbUU12 - 6*dalpha3*exAbUU13 +
    bDtrbDbeta1*invgamb11 + 3*hDhDbeta111*invgamb11 +
    bDtrbDbeta2*invgamb12 + 6*hDhDbeta121*invgamb12 +
    bDtrbDbeta3*invgamb13 + 6*hDhDbeta131*invgamb13 +
    3*hDhDbeta221*invgamb22 + 6*hDhDbeta231*invgamb23 +
    3*hDhDbeta331*invgamb33 + 3*LbetaLt1 + 2*ckappa3*Lt1*trbDbeta +
    2*trbDbeta*trDGam1 - 2*ckappa3*trbDbeta*trDGam1 + 6*ckappa1*psi4*ZU1 -
    6*ckappa3*hDbeta11*psi4*ZU1 - 6*ckappa3*hDbeta21*psi4*ZU2 -
    6*ckappa3*hDbeta31*psi4*ZU3 -
    6*(dalpha1*invgamb11 + dalpha2*invgamb12 + dalpha3*invgamb13)*
     Theta[ijk] + 2*alpha[ijk]*
     (3*DGam111*exAbUU11 + 18*dphi1*exAbUU11 + 6*DGam112*exAbUU12 +
       18*dphi2*exAbUU12 + 6*DGam113*exAbUU13 + 18*dphi3*exAbUU13 +
       3*DGam122*exAbUU22 + 6*DGam123*exAbUU23 + 3*DGam133*exAbUU33 +
       3*dTheta1*invgamb11 - 2*dtrK1*invgamb11 + 3*dTheta2*invgamb12 -
       2*dtrK2*invgamb12 + 3*dTheta3*invgamb13 - 2*dtrK3*invgamb13 -
       24*cpi*invgamb11*Sm1 - 24*cpi*invgamb12*Sm2 - 24*cpi*invgamb13*Sm3 -
       2*psi4*ZU1*trK[ijk]))/3.
;

const auto
dtLt2
=
(-6*dalpha1*exAbUU12 - 6*dalpha2*exAbUU22 - 6*dalpha3*exAbUU23 +
    3*hDhDbeta112*invgamb11 + bDtrbDbeta1*invgamb12 +
    6*hDhDbeta122*invgamb12 + 6*hDhDbeta132*invgamb13 +
    bDtrbDbeta2*invgamb22 + 3*hDhDbeta222*invgamb22 +
    bDtrbDbeta3*invgamb23 + 6*hDhDbeta232*invgamb23 +
    3*hDhDbeta332*invgamb33 + 3*LbetaLt2 + 2*ckappa3*Lt2*trbDbeta +
    2*trbDbeta*trDGam2 - 2*ckappa3*trbDbeta*trDGam2 -
    6*ckappa3*hDbeta12*psi4*ZU1 + 6*ckappa1*psi4*ZU2 -
    6*ckappa3*hDbeta22*psi4*ZU2 - 6*ckappa3*hDbeta32*psi4*ZU3 -
    6*(dalpha1*invgamb12 + dalpha2*invgamb22 + dalpha3*invgamb23)*
     Theta[ijk] + 2*alpha[ijk]*
     (3*DGam211*exAbUU11 + 6*DGam212*exAbUU12 + 18*dphi1*exAbUU12 +
       6*DGam213*exAbUU13 + 3*DGam222*exAbUU22 + 18*dphi2*exAbUU22 +
       6*DGam223*exAbUU23 + 18*dphi3*exAbUU23 + 3*DGam233*exAbUU33 +
       3*dTheta1*invgamb12 - 2*dtrK1*invgamb12 + 3*dTheta2*invgamb22 -
       2*dtrK2*invgamb22 + 3*dTheta3*invgamb23 - 2*dtrK3*invgamb23 -
       24*cpi*invgamb12*Sm1 - 24*cpi*invgamb22*Sm2 - 24*cpi*invgamb23*Sm3 -
       2*psi4*ZU2*trK[ijk]))/3.
;

const auto
dtLt3
=
(-6*dalpha1*exAbUU13 - 6*dalpha2*exAbUU23 - 6*dalpha3*exAbUU33 +
    3*hDhDbeta113*invgamb11 + 6*hDhDbeta123*invgamb12 +
    bDtrbDbeta1*invgamb13 + 6*hDhDbeta133*invgamb13 +
    3*hDhDbeta223*invgamb22 + bDtrbDbeta2*invgamb23 +
    6*hDhDbeta233*invgamb23 + bDtrbDbeta3*invgamb33 +
    3*hDhDbeta333*invgamb33 + 3*LbetaLt3 + 2*ckappa3*Lt3*trbDbeta +
    2*trbDbeta*trDGam3 - 2*ckappa3*trbDbeta*trDGam3 -
    6*ckappa3*hDbeta13*psi4*ZU1 - 6*ckappa3*hDbeta23*psi4*ZU2 +
    6*ckappa1*psi4*ZU3 - 6*ckappa3*hDbeta33*psi4*ZU3 -
    6*(dalpha1*invgamb13 + dalpha2*invgamb23 + dalpha3*invgamb33)*
     Theta[ijk] + 2*alpha[ijk]*
     (3*DGam311*exAbUU11 + 6*DGam312*exAbUU12 + 6*DGam313*exAbUU13 +
       18*dphi1*exAbUU13 + 3*DGam322*exAbUU22 + 6*DGam323*exAbUU23 +
       18*dphi2*exAbUU23 + 3*DGam333*exAbUU33 + 18*dphi3*exAbUU33 +
       3*dTheta1*invgamb13 - 2*dtrK1*invgamb13 + 3*dTheta2*invgamb23 -
       2*dtrK2*invgamb23 + 3*dTheta3*invgamb33 - 2*dtrK3*invgamb33 -
       24*cpi*invgamb13*Sm1 - 24*cpi*invgamb23*Sm2 - 24*cpi*invgamb33*Sm3 -
       2*psi4*ZU3*trK[ijk]))/3.
;

const auto
dtbeta1
=
B1 + beta1*hDbeta11 + beta2*hDbeta21 + beta3*hDbeta31
;

const auto
dtbeta2
=
B2 + beta1*hDbeta12 + beta2*hDbeta22 + beta3*hDbeta32
;

const auto
dtbeta3
=
B3 + beta1*hDbeta13 + beta2*hDbeta23 + beta3*hDbeta33
;

const auto
dtB1
=
(-4*B1*ceta + 3*dtLt1 + 4*beta1*hDB11 + 4*beta2*hDB21 + 4*beta3*hDB31 -
    3*beta1*hDLt11 - 3*beta2*hDLt21 - 3*beta3*hDLt31)/4.
;

const auto
dtB2
=
(-4*B2*ceta + 3*dtLt2 + 4*beta1*hDB12 + 4*beta2*hDB22 + 4*beta3*hDB32 -
    3*beta1*hDLt12 - 3*beta2*hDLt22 - 3*beta3*hDLt32)/4.
;

const auto
dtB3
=
(-4*B3*ceta + 3*dtLt3 + 4*beta1*hDB13 + 4*beta2*hDB23 + 4*beta3*hDB33 -
    3*beta1*hDLt13 - 3*beta2*hDLt23 - 3*beta3*hDLt33)/4.
;


dtepsOsph11[ijk]
=
dteps11
;

dtepsOsph12[ijk]
=
dteps12/R
;

dtepsOsph13[ijk]
=
(cscth*dteps13)/R
;

dtepsOsph22[ijk]
=
dteps22/Power(R,2)
;

dtepsOsph23[ijk]
=
(cscth*dteps23)/Power(R,2)
;

dtepsOsph33[ijk]
=
(Power(cscth,2)*dteps33)/Power(R,2)
;

dtexAbOsph11[ijk]
=
dtexAb11
;

dtexAbOsph12[ijk]
=
dtexAb12/R
;

dtexAbOsph13[ijk]
=
(cscth*dtexAb13)/R
;

dtexAbOsph22[ijk]
=
dtexAb22/Power(R,2)
;

dtexAbOsph23[ijk]
=
(cscth*dtexAb23)/Power(R,2)
;

dtexAbOsph33[ijk]
=
(Power(cscth,2)*dtexAb33)/Power(R,2)
;

dtLtOsph1[ijk]
=
dtLt1
;

dtLtOsph2[ijk]
=
dtLt2*R
;

dtLtOsph3[ijk]
=
dtLt3*R*sinth
;

dtbetaOsph1[ijk]
=
dtbeta1
;

dtbetaOsph2[ijk]
=
dtbeta2*R
;

dtbetaOsph3[ijk]
=
dtbeta3*R*sinth
;

dtBOsph1[ijk]
=
dtB1
;

dtBOsph2[ijk]
=
dtB2*R
;

dtBOsph3[ijk]
=
dtB3*R*sinth
;


  });
});

#endif // #ifndef CURVCCZ4_SET_RHS_HXX

/* CurvCCZ4_set_rhs.hxx */
