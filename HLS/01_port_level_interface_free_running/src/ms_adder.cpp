#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "hls/ap_fixpt.hpp"
#include <hls/ap_int.hpp>
#include <hls/axi_interface.hpp> //AXI4 Master インターフェースヘッダファイル

using namespace hls;

/*
 * https://microchiptech.github.io/fpga-hls-docs/userguide.html#top-level-rtl-interface
 * error.h見つからないコンパイルエラーが発生したらこれをやる
 * ln -s /usr/include/asm-generic /usr/include/asm
 * volatile キーワー ド データが揮発性で変化する可能性があると解釈される
 *
 * ap_start から ap_done の間に関数の入力や出力が変化する場合は、volatile を付ける
 * ap_uint<8>:interpret 8 bit uint as 8 bit
 * ap_int<4> :interpret 4 bit int as 4 bit
 */

#define TIMER_COUNT	2000000

void ms_free_running(ap_uint<2> indata, ap_uint<2> &outdata) {
#pragma HLS function top
#pragma HLS interface argument(indata) type(simple)
#pragma HLS interface argument(outdata) type(simple)

//	outdata=indata; //BIT1への参照
	ap_uint<2> tmp0=0;
	ap_uint<2> tmp1=0;

	//1) Pre-Process
	tmp0 = indata & (0x1<<0); //BIT0のみ抽出
	tmp1 = indata & (0x1<<1); //BIT1のみ抽出

	//2) Main-Process
	//	ap_uint<32> i;
	//	//動作クロック100MHzなので524289クロックカウント(約5.24ms)
	//	//動作クロック2MHzなので2000000クロックカウント
	//	for(i=0; i<2000000; i++){
	//		if(i == )
	//			i = 0;
	//		else
	//			i = i;
	//	}
//	DELAY_LOOP:for (volatile int j=0; j<TIMER_COUNT; j++); /*遅延を作成*/
	//3) Post-Process
	outdata=tmp0+tmp1;
}

int main() {
//	ap_uint<1> a=0;
//	ap_uint<1> b=0;

	ap_uint<4> AA(0xA);
	std::cout << "AA = " << AA << std::endl;
	ap_uint<8> BB(0xCB);
	std::cout << "BB = " << BB << std::endl;
	ap_uint<8> AB((AA, BB(3, 0))); // AB initialized as 0xAB
	std::cout << "AB = " << AB << std::endl;
	ap_uint<12> ABC((AA, ap_uint<4>(0xB), BB(7, 4))); // ABC initialized as 0xABC
	std::cout << "ABC = " << ABC << std::endl;


    // Verify output by comparing against a golden output.
    int mismatch_count = 0;
//    for (a=0; a<SIZE; a++){
//    	ms_adder(a, b);
//#ifndef __SYNTHESIS__
//    	std::cout << "add_out = " << a << "->" << b << std::endl;
//        mismatch_count++;
//#endif
//    }
//    if (mismatch_count == 0)
//        printf("PASS!\n");
//    else
//        printf("FAIL with %d differences\n", mismatch_count);
    return mismatch_count;
}
