/* CurvCCZ4_set_rhs.hxx */
/* Produced with Generato */

#ifndef CURVCCZ4_SET_RHS_HXX
#define CURVCCZ4_SET_RHS_HXX

const auto dtphi = gf_dtphi;
const auto dttrK = gf_dttrK;
const auto dtTheta = gf_dtTheta;
const auto dtalpha = gf_dtalpha;
const auto dtepsOrth11 = gf_dteps[0];
const auto dtepsOrth12 = gf_dteps[1];
const auto dtepsOrth13 = gf_dteps[2];
const auto dtepsOrth22 = gf_dteps[3];
const auto dtepsOrth23 = gf_dteps[4];
const auto dtepsOrth33 = gf_dteps[5];
const auto dtexAbOrth11 = gf_dtexAb[0];
const auto dtexAbOrth12 = gf_dtexAb[1];
const auto dtexAbOrth13 = gf_dtexAb[2];
const auto dtexAbOrth22 = gf_dtexAb[3];
const auto dtexAbOrth23 = gf_dtexAb[4];
const auto dtexAbOrth33 = gf_dtexAb[5];
const auto dtLtOrth1 = gf_dtLt[0];
const auto dtLtOrth2 = gf_dtLt[1];
const auto dtLtOrth3 = gf_dtLt[2];
const auto dtbetaOrth1 = gf_dtbeta[0];
const auto dtbetaOrth2 = gf_dtbeta[1];
const auto dtbetaOrth3 = gf_dtbeta[2];
const auto dtBOrth1 = gf_dtB[0];
const auto dtBOrth2 = gf_dtB[1];
const auto dtBOrth3 = gf_dtB[2];

noinline([&]() __attribute__((__flatten__, __hot__)) {
grid.loop_int_device<0, 0, 0>(
  grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {
const int ijk = layout2.linear(p.i, p.j, p.k);

const auto coX = p.x;
const auto coY = p.y;
const auto coZ = p.z;

  });
});

#endif // #ifndef CURVCCZ4_SET_RHS_HXX

/* CurvCCZ4_set_rhs.hxx */
