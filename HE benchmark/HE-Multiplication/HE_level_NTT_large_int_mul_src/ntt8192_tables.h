/*
 * Parameters:
 * - q = 85236826359346144956638323529482240001
 * - n = 8192
 * - psi = 30096022330904601746630191129002008647
 * - omega = psi^2 = 53148607008388425280033337649579441711
 * - inverse of psi = 31810531169415839797488499450009303154
 * - inverse of omega = 72442362355958027916976823508184643857
 * - inverse of n = 85226421473315951335427796390379520001
 */

#ifndef __NTT8192_TABLES_H
#define __NTT8192_TABLES_H

#include <stdint.h>

#include <ap_int.h>

/*
 * PARAMETERS
 */
static const ap_int<128> ntt8192_psi = "0x16a44876b64f44ab4e806ff0b7cc6047";
static const ap_int<128> ntt8192_omega = "0x27fc0ca3c622e0979bb30afd19d43e2f";
static const ap_int<128> ntt8192_inv_psi = "0x17ee7c469f3292fa86b77b5a067b3872";
static const ap_int<128> ntt8192_inv_omega = "0x367fe438b625c12d1c5a7d384848b911";
static const ap_int<128> ntt8192_inv_n = "0x401e02ffe00000000000000000000001";

/*
 * POWERS OF PSI
 */
extern const ap_uint<128> ntt8192_psi_powers[8192];
extern const ap_uint<128> ntt8192_inv_psi_powers[8192];
extern const ap_uint<128> ntt8192_scaled_inv_psi_powers[8192];

/*
 * TABLES FOR NTT COMPUTATION
 */
extern const ap_uint<128> ntt8192_omega_powers[8192];
extern const ap_uint<128> ntt8192_omega_powers_rev[8192];
extern const ap_uint<128> ntt8192_inv_omega_powers[8192];
extern const ap_uint<128> ntt8192_inv_omega_powers_rev[8192];
extern const ap_uint<128> ntt8192_mixed_powers[8192];
extern const ap_uint<128> ntt8192_mixed_powers_rev[8192];
extern const ap_uint<128> ntt8192_inv_mixed_powers[8192];
extern const ap_uint<128> ntt8192_inv_mixed_powers_rev[8192];

#endif /* __NTT8192_TABLES_H */
