
set TopModule "ntt8192_int_product"
set ClockPeriod 2.5
set ClockList ap_clk
set HasVivadoClockPeriod 0
set CombLogicFlag 0
set PipelineFlag 0
set DataflowTaskPipelineFlag 1
set TrivialPipelineFlag 0
set noPortSwitchingFlag 0
set FloatingPointFlag 0
set FftOrFirFlag 0
set NbRWValue 0
set intNbAccess 0
set NewDSPMapping 1
set HasDSPModule 0
set ResetLevelFlag 0
set ResetStyle control
set ResetSyncFlag 1
set ResetRegisterFlag 1
set ResetVariableFlag 0
set ResetRegisterNum 3
set FsmEncStyle onehot
set MaxFanout 0
set RtlPrefix {}
set RtlSubPrefix ntt8192_int_product_
set ExtraCCFlags {}
set ExtraCLdFlags {}
set SynCheckOptions {}
set PresynOptions {}
set PreprocOptions {}
set SchedOptions {}
set BindOptions {}
set RtlGenOptions {}
set RtlWriterOptions {}
set CbcGenFlag {}
set CasGenFlag {}
set CasMonitorFlag {}
set AutoSimOptions {}
set ExportMCPathFlag 0
set SCTraceFileName mytrace
set SCTraceFileFormat vcd
set SCTraceOption all
set TargetInfo xcvu11p:-flga2577:-1-e
set SourceFiles {sc {} c {../../../HE_level_NTT_large_int_mul_src/ntt8192_tables.h ../../../HE_level_NTT_large_int_mul_src/ntt8192_tables.cpp ../../../HE_level_NTT_large_int_mul_src/ntt.h ../../../HE_level_NTT_large_int_mul_src/ntt.cpp ../../../HE_level_NTT_large_int_mul_src/ntt8192.h ../../../HE_level_NTT_large_int_mul_src/ntt8192.cpp}}
set SourceFlags {sc {} c {{ } {} { } {} { } {} { } {} { } {} { } {}}}
set DirectiveFile /home/asyam/Desktop/NTT/tfhe-ntt/HE-Multiplication-Million-bit-Mul-512-1024/HE_level_NTT_large_int_mul/ntt8192_int_product/solution1/solution1.directive
set TBFiles {verilog {../../../HE_level_NTT_large_int_mul_src/sort.h ../../../HE_level_NTT_large_int_mul_src/sort.cpp ../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp} bc {../../../HE_level_NTT_large_int_mul_src/sort.h ../../../HE_level_NTT_large_int_mul_src/sort.cpp ../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp} sc {../../../HE_level_NTT_large_int_mul_src/sort.h ../../../HE_level_NTT_large_int_mul_src/sort.cpp ../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp} vhdl {../../../HE_level_NTT_large_int_mul_src/sort.h ../../../HE_level_NTT_large_int_mul_src/sort.cpp ../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp} c {} cas {../../../HE_level_NTT_large_int_mul_src/sort.h ../../../HE_level_NTT_large_int_mul_src/sort.cpp ../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp}}
set SpecLanguage C
set TVInFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TVOutFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TBTops {verilog {} bc {} sc {} vhdl {} c {} cas {}}
set TBInstNames {verilog {} bc {} sc {} vhdl {} c {} cas {}}
set XDCFiles {}
set ExtraGlobalOptions {"area_timing" 1 "clock_gate" 1 "impl_flow" map "power_gate" 0}
set TBTVFileNotFound {}
set AppFile ../hls.app
set ApsFile solution1.aps
set AvePath ../..
set DefaultPlatform DefaultPlatform
set multiClockList {}
set SCPortClockMap {}
set intNbAccess 0
set PlatformFiles {{DefaultPlatform {xilinx/virtexuplus/virtexuplus}}}
set HPFPO 0
