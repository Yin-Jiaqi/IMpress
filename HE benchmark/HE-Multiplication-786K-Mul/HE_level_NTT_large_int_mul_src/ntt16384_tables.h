/*
 * Parameters:
 * - q = 115763822272329310636028559609001827025179711501300126126825041166177555972097
 * - n = 16384
 * - psi = 29658549744383932097725828729879209739837992032026018213687954560314496381961
 * - omega = psi^2 = 30660961880184576368694163361888707542685529914309576418100574883369102729189
 * - inverse of psi = 14512727885866963591169316104941145577831266102479146888402624634320703313955
 * - inverse of omega = 68211104537482110951433531187059124148544588312229637736506434325970947287262
 * - inverse of n = 115756756609348821786502434818986629159760694184924314351548745692473565642753
 */

#ifndef __NTT16384_TABLES_H
#define __NTT16384_TABLES_H

#include <stdint.h>

#include <ap_int.h>

/*
 * PARAMETERS
 */
static const ap_int<260> ntt16384_psi = "0x419224ef52c8dadb071f89941282a8633f76eacc25cb9bbbc3f46309c0b9f409";
static const ap_int<260> ntt16384_omega = "0x43c97d4beb738d89af7a237f0ca343d37490fb23cb424a96afb05ba486f5dfe5";
static const ap_int<260> ntt16384_inv_psi = "0x2015e9b36006f2355c568e344b93df83413e5bf1e95022f6674696b97011d823";
static const ap_int<260> ntt16384_inv_omega = "0x96ce1df4f4c3d641db974c26fadb6c9286a4f5699a3481131879c75f6bb228de";
static const ap_int<260> ntt16384_inv_n = "0xffec009ffd8004fffc0000000000000000000000000000000000000000000001";

/*
 * POWERS OF PSI
 */
extern const ap_uint<260> ntt16384_psi_powers[16384];
extern const ap_uint<260> ntt16384_inv_psi_powers[16384];
extern const ap_uint<260> ntt16384_scaled_inv_psi_powers[16384];

/*
 * TABLES FOR NTT COMPUTATION
 */
extern const ap_uint<260> ntt16384_omega_powers[16384];
extern const ap_uint<260> ntt16384_omega_powers_rev[16384];
extern const ap_uint<260> ntt16384_inv_omega_powers[16384];
extern const ap_uint<260> ntt16384_inv_omega_powers_rev[16384];
extern const ap_uint<260> ntt16384_mixed_powers[16384];
extern const ap_uint<260> ntt16384_mixed_powers_rev[16384];
extern const ap_uint<260> ntt16384_inv_mixed_powers[16384];
extern const ap_uint<260> ntt16384_inv_mixed_powers_rev[16384];

#endif /* __NTT16384_TABLES_H */
