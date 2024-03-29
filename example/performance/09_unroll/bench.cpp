#include "bench.h"

int RunBenchmark(int param, int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < param;i++)
	{
		sum += data[i];
	}
	return(sum);
}
int RunBenchmark8(int param, int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < param;i+=8)
	{
		sum += data[i];
		sum += data[i+1];
		sum += data[i+2];
		sum += data[i+3];
		sum += data[i+4];
		sum += data[i+5];
		sum += data[i+6];
		sum += data[i+7];
	}
	return(sum);
}
int RunBenchmark16(int param, int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < param;i+=16)
	{
		sum += data[i];
		sum += data[i+1];
		sum += data[i+2];
		sum += data[i+3];
		sum += data[i+4];
		sum += data[i+5];
		sum += data[i+6];
		sum += data[i+7];
		sum += data[i+8];
		sum += data[i+9];
		sum += data[i+10];
		sum += data[i+11];
		sum += data[i+12];
		sum += data[i+13];
		sum += data[i+14];
		sum += data[i+15];
	}
	return(sum);
}
int RunBenchmark64(int param, int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < param;i+=64)
	{
		sum += data[i];
		sum += data[i+1];
		sum += data[i+2];
		sum += data[i+3];
		sum += data[i+4];
		sum += data[i+5];
		sum += data[i+6];
		sum += data[i+7];
		sum += data[i+8];
		sum += data[i+9];
		sum += data[i+10];
		sum += data[i+11];
		sum += data[i+12];
		sum += data[i+13];
		sum += data[i+14];
		sum += data[i+15];
		sum += data[i+16];
		sum += data[i+17];
		sum += data[i+18];
		sum += data[i+19];
		sum += data[i+20];
		sum += data[i+21];
		sum += data[i+22];
		sum += data[i+23];
		sum += data[i+24];
		sum += data[i+25];
		sum += data[i+26];
		sum += data[i+27];
		sum += data[i+28];
		sum += data[i+29];
		sum += data[i+30];
		sum += data[i+31];
		sum += data[i+32];
		sum += data[i+33];
		sum += data[i+34];
		sum += data[i+35];
		sum += data[i+36];
		sum += data[i+37];
		sum += data[i+38];
		sum += data[i+39];
		sum += data[i+40];
		sum += data[i+41];
		sum += data[i+42];
		sum += data[i+43];
		sum += data[i+44];
		sum += data[i+45];
		sum += data[i+46];
		sum += data[i+47];
		sum += data[i+48];
		sum += data[i+49];
		sum += data[i+50];
		sum += data[i+51];
		sum += data[i+52];
		sum += data[i+53];
		sum += data[i+54];
		sum += data[i+55];
		sum += data[i+56];
		sum += data[i+57];
		sum += data[i+58];
		sum += data[i+59];
		sum += data[i+60];
		sum += data[i+61];
		sum += data[i+62];
		sum += data[i+63];
	}
	return(sum);
}

int RunBenchmark256(int param, int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < param;i+=64)
	{
		sum += data[i];
		sum += data[i+1];
		sum += data[i+2];
		sum += data[i+3];
		sum += data[i+4];
		sum += data[i+5];
		sum += data[i+6];
		sum += data[i+7];
		sum += data[i+8];
		sum += data[i+9];
		sum += data[i+10];
		sum += data[i+11];
		sum += data[i+12];
		sum += data[i+13];
		sum += data[i+14];
		sum += data[i+15];
		sum += data[i+16];
		sum += data[i+17];
		sum += data[i+18];
		sum += data[i+19];
		sum += data[i+20];
		sum += data[i+21];
		sum += data[i+22];
		sum += data[i+23];
		sum += data[i+24];
		sum += data[i+25];
		sum += data[i+26];
		sum += data[i+27];
		sum += data[i+28];
		sum += data[i+29];
		sum += data[i+30];
		sum += data[i+31];
		sum += data[i+32];
		sum += data[i+33];
		sum += data[i+34];
		sum += data[i+35];
		sum += data[i+36];
		sum += data[i+37];
		sum += data[i+38];
		sum += data[i+39];
		sum += data[i+40];
		sum += data[i+41];
		sum += data[i+42];
		sum += data[i+43];
		sum += data[i+44];
		sum += data[i+45];
		sum += data[i+46];
		sum += data[i+47];
		sum += data[i+48];
		sum += data[i+49];
		sum += data[i+50];
		sum += data[i+51];
		sum += data[i+52];
		sum += data[i+53];
		sum += data[i+54];
		sum += data[i+55];
		sum += data[i+56];
		sum += data[i+57];
		sum += data[i+58];
		sum += data[i+59];
		sum += data[i+60];
		sum += data[i+61];
		sum += data[i+62];
		sum += data[i+63];
		sum += data[i+64];
		sum += data[i+65];
		sum += data[i+66];
		sum += data[i+67];
		sum += data[i+68];
		sum += data[i+69];
		sum += data[i+70];
		sum += data[i+71];
		sum += data[i+72];
		sum += data[i+73];
		sum += data[i+74];
		sum += data[i+75];
		sum += data[i+76];
		sum += data[i+77];
		sum += data[i+78];
		sum += data[i+79];
		sum += data[i+80];
		sum += data[i+81];
		sum += data[i+82];
		sum += data[i+83];
		sum += data[i+84];
		sum += data[i+85];
		sum += data[i+86];
		sum += data[i+87];
		sum += data[i+88];
		sum += data[i+89];
		sum += data[i+90];
		sum += data[i+91];
		sum += data[i+92];
		sum += data[i+93];
		sum += data[i+94];
		sum += data[i+95];
		sum += data[i+96];
		sum += data[i+97];
		sum += data[i+98];
		sum += data[i+99];
		sum += data[i+100];
		sum += data[i+101];
		sum += data[i+102];
		sum += data[i+103];
		sum += data[i+104];
		sum += data[i+105];
		sum += data[i+106];
		sum += data[i+107];
		sum += data[i+108];
		sum += data[i+109];
		sum += data[i+110];
		sum += data[i+111];
		sum += data[i+112];
		sum += data[i+113];
		sum += data[i+114];
		sum += data[i+115];
		sum += data[i+116];
		sum += data[i+117];
		sum += data[i+118];
		sum += data[i+119];
		sum += data[i+120];
		sum += data[i+121];
		sum += data[i+122];
		sum += data[i+123];
		sum += data[i+124];
		sum += data[i+125];
		sum += data[i+126];
		sum += data[i+127];
		sum += data[i+128];
		sum += data[i+129];
		sum += data[i+130];
		sum += data[i+131];
		sum += data[i+132];
		sum += data[i+133];
		sum += data[i+134];
		sum += data[i+135];
		sum += data[i+136];
		sum += data[i+137];
		sum += data[i+138];
		sum += data[i+139];
		sum += data[i+140];
		sum += data[i+141];
		sum += data[i+142];
		sum += data[i+143];
		sum += data[i+144];
		sum += data[i+145];
		sum += data[i+146];
		sum += data[i+147];
		sum += data[i+148];
		sum += data[i+149];
		sum += data[i+150];
		sum += data[i+151];
		sum += data[i+152];
		sum += data[i+153];
		sum += data[i+154];
		sum += data[i+155];
		sum += data[i+156];
		sum += data[i+157];
		sum += data[i+158];
		sum += data[i+159];
		sum += data[i+160];
		sum += data[i+161];
		sum += data[i+162];
		sum += data[i+163];
		sum += data[i+164];
		sum += data[i+165];
		sum += data[i+166];
		sum += data[i+167];
		sum += data[i+168];
		sum += data[i+169];
		sum += data[i+170];
		sum += data[i+171];
		sum += data[i+172];
		sum += data[i+173];
		sum += data[i+174];
		sum += data[i+175];
		sum += data[i+176];
		sum += data[i+177];
		sum += data[i+178];
		sum += data[i+179];
		sum += data[i+180];
		sum += data[i+181];
		sum += data[i+182];
		sum += data[i+183];
		sum += data[i+184];
		sum += data[i+185];
		sum += data[i+186];
		sum += data[i+187];
		sum += data[i+188];
		sum += data[i+189];
		sum += data[i+190];
		sum += data[i+191];
		sum += data[i+192];
		sum += data[i+193];
		sum += data[i+194];
		sum += data[i+195];
		sum += data[i+196];
		sum += data[i+197];
		sum += data[i+198];
		sum += data[i+199];
		sum += data[i+200];
		sum += data[i+201];
		sum += data[i+202];
		sum += data[i+203];
		sum += data[i+204];
		sum += data[i+205];
		sum += data[i+206];
		sum += data[i+207];
		sum += data[i+208];
		sum += data[i+209];
		sum += data[i+210];
		sum += data[i+211];
		sum += data[i+212];
		sum += data[i+213];
		sum += data[i+214];
		sum += data[i+215];
		sum += data[i+216];
		sum += data[i+217];
		sum += data[i+218];
		sum += data[i+219];
		sum += data[i+220];
		sum += data[i+221];
		sum += data[i+222];
		sum += data[i+223];
		sum += data[i+224];
		sum += data[i+225];
		sum += data[i+226];
		sum += data[i+227];
		sum += data[i+228];
		sum += data[i+229];
		sum += data[i+230];
		sum += data[i+231];
		sum += data[i+232];
		sum += data[i+233];
		sum += data[i+234];
		sum += data[i+235];
		sum += data[i+236];
		sum += data[i+237];
		sum += data[i+238];
		sum += data[i+239];
		sum += data[i+240];
		sum += data[i+241];
		sum += data[i+242];
		sum += data[i+243];
		sum += data[i+244];
		sum += data[i+245];
		sum += data[i+246];
		sum += data[i+247];
		sum += data[i+248];
		sum += data[i+249];
		sum += data[i+250];
		sum += data[i+251];
		sum += data[i+252];
		sum += data[i+253];
		sum += data[i+254];
		sum += data[i+255];
	}
	return(sum);
}