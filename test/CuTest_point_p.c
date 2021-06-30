#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../release/secp256k1.h"

#define scalarEq(exp, res, msg) CuAssertLongLongEquals_Msg(tc, msg, (exp)[0], (res)[0]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[1], (res)[1]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[2], (res)[2]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[3], (res)[3])
void printScalar(char *msg, long long *s){
    printf("%s\n",msg);
    printf("//%016llX%016llX%016llX%016llX\n", s[3],s[2], s[1], s[0]); 
    printf("Scalar %s = ",msg);
    printf("{0x%016llX, 0x%016llX, 0x%016llX, 0x%016llX};\n\n", s[0],s[1], s[2], s[3]); 
} 
void printPoint(Point *p){
    printf("char inp[] = \"04%016llX%016llX%016llX%016llX", p->x[3],p->x[2], p->x[1], p->x[0]); 
    printf("%016llX%016llX%016llX%016llX\";\n", p->y[3],p->y[2], p->y[1], p->y[0]); 
    printf("Point exp = {{0x%016llX, 0x%016llX, 0x%016llX, 0x%016llX},", p->x[0],p->x[1], p->x[2], p->x[3]); 
    printf(" {0x%016llX, 0x%016llX, 0x%016llX, 0x%016llX}};\n\n", p->y[0],p->y[1], p->y[2], p->y[3]); 
} 


//******************************************* Tests for Points on the secp255k1 curve **************************************************************************

void Test_add_different_points_1(CuTest *tc){

        Point exp = {{0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a }, 
        				{0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}}; 
        Point p1 = {{0x15B6102F43228506, 0x2E4EB529ED776E92, 0x10DAE4C62A4520DD, 0x4D696DF0B0F1C4C1},
        				{0x97A110D0A2682360, 0xDE221EA11AE3A483, 0x0769C4B534C00831, 0xD9C5BF1AC94B5C7F}};
        Point p2 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870}, 
        				{0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}


void Test_add_different_points_2(CuTest *tc){

        Point exp = {{0x98C13CA84DB6A392, 0xC832C50E9B1EEF8A, 0xDEF2B65EE8C8B17D, 0x6D0A80195FF48CC4 }, 
        				{0xA17A800BEE319F96,0xBBEAB4B55A15F295,0xEC17A721F0F0BAF8,0x6B47A61FD59BF8D0}}; 
        Point p1 = {{0xB26AF1F9B853983D, 0x299E84FCBF0B98AF, 0x9894B97A3990AAD5,0xE315F81399469D5A },
        			   {0xC5C81620CBA96983,0xEEBB7348E27E7918 ,0x1227B0B98A468469 ,0x86F325BB8701D0C2 }};
        Point p2 = {{0xABAC09B95C709EE5, 0x5C778E4B8CEF3CA7, 0x3045406E95C07CD8, 0xC6047F9441ED7D6D}, 
        				{0x236431A950CFE52A, 0xF7F632653266D0E1, 0xA3C58419466CEAEE, 0x1AE168FEA63DC339}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_3(CuTest *tc){

		Point exp = {{0x7573D644A1C279B2, 0x778ED5CD442392AE, 0xBF405DA152F1B7DA, 0x60087A99DDA9CE3D },
						{0x4077C1C554A7D3FC, 0x3563D7A11690BCE0, 0xE2BA6984F86D1E0B, 0x922A1CCD38EA29FE}};
        Point p1 = {{0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                       {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};

        Point p2 = {{0xad8a04887e5b2352,0xb53f53e486d8511d,0x2fe83c1af1a8403c,0x50863ad64a87ae8a},
        			   {0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_4(CuTest *tc){

        Point  exp = {{0xF5A1ADDCF2740D18, 0x586BE9D91E090D3B, 0xC0F1450D891FCE3A, 0xD6E069598E0C64D1},
                {0xABB54CC7E8EE63FF, 0x2F39929151D4823F, 0x41D64D857F9043E5, 0x9CED083529EADC99}};
        Point p1 = {{0x52b465135504e4ff, 0x97d573e36ed4385f, 0x72808056ee1e53f4, 0x74f1ce3c6ef778d6},
                       {0xd127a2980b361248, 0x7a8a2d551742bf50, 0x3aa92456dca573e0, 0xa416475ada0fd256}};
        Point p2 = {{0xc88923705f74ebe3, 0x0bc5ad357953ce83, 0x925ed15291736225, 0x34da6a5fe7e64ea7},
                       {0xe3597b1c29e91d01, 0xda517498d863708a, 0xd93a09e9ec7f98d0, 0xea775f9faa9a41e0}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}


void Test_add_different_points_5(CuTest *tc){

        Point exp = {{0xAF7CC5C9213E9DDD, 0xAB40F82D4E621D08, 0x29DC4C11603AC327, 0x28158CAAA9057D23},
                        {0x2625C5AB6BE6591E, 0x4946DB84DD4591B7, 0x5FD31AD41DF4D271, 0x4CB64D69F23E982D}};
        Point p1 = {{0x52b465135504e4ff, 0x97d573e36ed4385f, 0x72808056ee1e53f4, 0x74f1ce3c6ef778d6},
        			   {0xd127a2980b361248, 0x7a8a2d551742bf50, 0x3aa92456dca573e0, 0xa416475ada0fd256}};
        Point p2 = {{0x002b28f4bf894477, 0x1dfa93a9285b2f4f, 0xa02640eb88cb0cfd, 0x4f83a657a0ced2b1},
        			   {0xccaa9b5070c81633, 0x3e7be1ab6af1d6ca, 0xfb5c05a28b88b074, 0x9e1c64324941d002}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_6(CuTest *tc){

        Point exp = {{0x1A1F2588CD8C7B99, 0x81749EA2B53B91ED, 0xEC180C0285E45304, 0x7BADB382A0797000},  
        				{0xC0FA98A3F7FCCEC2, 0x2CBA625E86C48F78, 0xEF4EBF083546CDFD, 0x1545DD745F9F38C9}};
        Point p1 = {{0x66631d7c87fa6b09, 0xea7fb259af59d80f, 0xa3b4f953c203dae6, 0x827bbf04097867c2},
                       {0x2e6693e32d6f7566, 0x89befd00d4990a7b, 0xefc0d777f026b087, 0x842a5d53da72e8d9}};
        Point p2 = {{0xC88923705F74EBE3, 0x0BC5AD357953CE83, 0x925ED15291736225, 0x34DA6A5FE7E64EA7},
                       {0xE3597B1C29E91D01, 0xDA517498D863708A, 0xD93A09E9EC7F98D0, 0xEA775F9FAA9A41E0}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_7(CuTest *tc){

        Point exp = {{0xACB54C27F91ABE08, 0xC670890B1DD15B2E, 0x20B45E69A24D0BAF, 0xAAB2F658611D3D91},
						{0x472FF554140E8973, 0xD61AC4F6D3C8F019, 0x1FC3CF123E1FAE1B, 0x9994E302D89D67D7}};
        Point p1 = {{0xDFF8D267A3897561, 0x0733EF5B3F4CE687, 0x0E72E26F8ACFD6FA, 0x1A72C74ECF959A74},
                         {0xC5A446144AE742BD, 0x96D2F74DECE41AF7, 0x85575C3AB2990E69, 0xA206BAFD335B12CE}};
        Point p2 = {{0xB8ED1D28C6C0E474, 0xD65C19F210F45DE9, 0x6E7B7C5BBC85A579, 0x729ED24498A577A3},
                         {0x2B560859353A8E19, 0x7215799DDE7E7442, 0xEB1F919866D297FD, 0xA91DCE1C9336D628}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_8(CuTest *tc){

        Point exp = { {0xE92BDDEDCAC4F9BC, 0x3D419B7E0330E39C, 0xA398F365F2EA7A0E, 0x5CBDF0646E5DB4EA},
                         {0xA5082628087264DA, 0xA813D0B813FDE7B5, 0xA3178D6D861A54DB, 0x6AEBCA40BA255960}};//7G
        Point p1 = { {0x8601F113BCE036F9, 0xB531C845836F99B0, 0x49344F85F89D5229, 0xF9308A019258C310},
                        {0x6CB9FD7584B8E672, 0x6500A99934C2231B, 0x0FE337E62A37F356, 0x388F7B0F632DE814}};//input: 3G
        Point p2 = {{0x74FA94ABE8C4CD13, 0xCC6C13900EE07584, 0x581E4904930B1404, 0xE493DBF1C10D80F3},
                       {0xCFE97BDC47739922, 0xD967AE33BFBDFE40, 0x5642E2098EA51448, 0x51ED993EA0D455B7}};//input: 4G
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}


void Test_add_different_points_9(CuTest *tc){

        Point exp = { {0x8601F113BCE036F9, 0xB531C845836F99B0, 0x49344F85F89D5229, 0xF9308A019258C310},
                         {0x6CB9FD7584B8E672, 0x6500A99934C2231B, 0x0FE337E62A37F356, 0x388F7B0F632DE814}};//3G
        Point p1 = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                       {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//input: G
        Point p2 = { {0xABAC09B95C709EE5, 0x5C778E4B8CEF3CA7, 0x3045406E95C07CD8, 0xC6047F9441ED7D6D},
                        {0x236431A950CFE52A, 0xF7F632653266D0E1, 0xA3C58419466CEAEE, 0x1AE168FEA63DC339}};//input: 2G
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}


void Test_add_different_points_10(CuTest *tc){

        Point exp = {{0xA6F0146894AE298F,0x92880838C85D6AC0,0x44B9CC0DD5B7530A,0xB68B69A717D220F7},
                         {0x30731EBC29648EA0,0x96876FA217206006,0x86038570733AD6EA,0x863978F7A606A4DB}};
        Point p1 = {{0xFC2A15DF5570D417,0x5326EE294BB33D45,0x112C258B808B9BBF,0xE8AFB71910C1E2A0},
     	                 {0x0BDF710DFD3E1487,0x0877D5F8AED5F471,0x470ACD54EFBB5694,0x4F712F0FB74E7467}};
        Point p2 = {{0xE548DA3ADD7A673E,0x6E1ED105333CA92F,0x6FCB01B0963134ED,0xB1D8DABC9FF75A95},
                         {0x70F7C21D2DA3955A,0xC3387E96A0855167,0x6D1D5C598737AC50,0xA6503D7508A09DEA}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_11(CuTest *tc){

        Point exp = {{0x2C0402C2BA51D4EE,0x8E46F1D66DF34FFF,0xC0DBCA779584BEBB,0xF9CDDDA817150CEB},
                         {0xE36EE91E4C9AA276,0x3300C29EF2E73BE9,0x4DD3481BDF98E16B,0xE68409628925B679}};
        Point p1 = {{0x3371D350150E96FE,0xB05892D6C6A46FBF,0x8BE659471C770FB5,0x0B00592A587731CA},                             
                        {0x36746F41DFFF09A0,0x43F2829888C191AA,0x1D536E704748CFFB,0x6BDC9456D4D089CD}};
        Point p2 = {{0x4DDE2837A3D3F5D5,0x24A57B5865FFE641,0x76C36C3E00CE0549,0x8A342ECD31232055},
                         {0x8DF92078D3E41E1B,0x6D9E52275389C032,0xA82D7CC580222E0A,0x1EF8189771D704AF}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_12(CuTest *tc){

        Point exp ={{0x349A00A472818766, 0xDE6FC343A529DDC1, 0x5213373198D70837, 0xEC6BD14FA8E2FB5B},
                       {0xAD4C286ED3BBD982, 0x028ED2447305351B, 0xFAB0D54DA2DAEADD, 0x2A461C37BAF43625}};//{101,101,101,101}*G        
        Point p1 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point p2 = {{0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_different_points_13(CuTest *tc){
        Point exp = {{0xED0669955270548A, 0x792C00A226005FC2,0x8449135B0C3D0C09 , 0x533210F4AFABD74E},
                        {0x7702D167DE9C09C3, 0xF3819AB954AB1E50, 0x234731C10D6768F6, 0xC7A955AABA76CBBF}};//{137,100,100,100}*G        
                       
        Point p1 = { {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49},
                        {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010}};//{37,0,0,0}*G
        Point p2 = {{0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
		Point p3;		
		secp256k1_add_different_points(&p1,&p2,&p3);    
        scalarEq(exp.x, p3.x, "p3.x != exp.x");
        scalarEq(exp.y, p3.y, "p3.y != exp.y");
}

void Test_add_asign_14(CuTest *tc){
        //This test should fail because secp256k1_add_different_points adds only different points, but p1 == p2  
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G      
        Point p1 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point p2 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point p3;
        int exp_res = 1;             
		secp256k1_add_different_points(&p1,&p2,&p3);  
        int res =  secp256k1_compare_points(&p3,&exp);   //different points: 1, equal points: 0
		CuAssertIntEquals_Msg(tc, "p1==sum",exp_res,res);  
}

//***************Point doubling*****************

void Test_double_point_1(CuTest *tc){
        Point a ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
        Point exp = {{0xABAC09B95C709EE5, 0x5C778E4B8CEF3CA7, 0x3045406E95C07CD8, 0xC6047F9441ED7D6D},
                     {0x236431A950CFE52A, 0xF7F632653266D0E1, 0xA3C58419466CEAEE, 0x1AE168FEA63DC339}};
        Point res;
        secp256k1_double_point(&a, &res);
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
        
}

void Test_double_point_2(CuTest *tc){
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G
        Point a  = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point res;
        secp256k1_double_point(&a, &res);
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
        
}

void Test_double_point_3(CuTest *tc){

        Point a ={{0xE92BDDEDCAC4F9BC, 0x3D419B7E0330E39C, 0xA398F365F2EA7A0E,0x5CBDF0646E5DB4EA},
					   {0xA5082628087264DA,0xA813D0B813FDE7B5,0xA3178D6D861A54DB,0x6AEBCA40BA255960}};//7*G
   
        Point exp  = {{0xE49B241A60E823E4,0x26AA7B63678949E6,0xFD64E67F07D38E32,0x499FDF9E895E719C },
                         {0xC65F40D403A13F5B,0x464279C27A3F95BC,0x90F044E4A7B3D464,0xCAC2F6C4B54E8551}};//14*G
        Point res;
        secp256k1_double_point(&a, &res);
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
        
}

/** **********************************Compare points ********************/

void Test_compare_1(CuTest *tc){
        Point a = {{1,1,1,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 0; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a!=b",exp,res);
}

void Test_compare_2(CuTest *tc){
        Point a = {{8,1,1,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}


void Test_compare_3(CuTest *tc){
        Point a = {{1,8,1,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

void Test_compare_4(CuTest *tc){
        Point a = {{1,1,8,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

void Test_compare_5(CuTest *tc){
        Point a = {{1,1,1,8},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

void Test_compare_6(CuTest *tc){
        Point a = {{1,1,1,1},{8,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

void Test_compare_7(CuTest *tc){
        Point a = {{1,1,1,1},{1,8,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

void Test_compare_8(CuTest *tc){
        Point a = {{1,1,1,1},{1,1,8,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

void Test_compare_9(CuTest *tc){
        Point a = {{1,1,1,1},{1,1,1,8}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        CuAssertIntEquals_Msg(tc, "a==b",exp,res);
}

/********************************* generator multiplication *****************************************************/

void Test_generator_mul_1(CuTest *tc){
        Scalar k = {  0x20653B12448E00FD, 0xCAE8E2EFD506619D, 0xA21CF70BA2B3A52F, 0xA302FDA67E896BA4};
        Point exp ={ {0x51205AF4CAA22825, 0xDA22AB7288CEC20A, 0x92D98A24047BB8B4, 0x2C3143909EC74F67},
						{0x9CF18D0C261F9F13, 0x7029736F1B7E8D65, 0xAE4CB2D7780770DA, 0x9F0C1DA1C1052260}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}


void Test_generator_mul_2(CuTest *tc){
        Scalar k = {37, 0,0,0}; 
        Point exp ={ {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49},
                        {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010}};//{37,0,0,0}*G
        Point res;
		secp256k1_generator_mul(k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");

}

void Test_generator_mul_3(CuTest *tc){
        Scalar k = {2, 2,2,2}; 
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G
        Point res;
        
		secp256k1_generator_mul(k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");

}

void Test_generator_mul_4(CuTest *tc){
        Scalar k = {100, 100,100,100};
        Point exp ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
        Point res;
		secp256k1_generator_mul(k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}

void Test_generator_mul_5(CuTest *tc){
        Scalar k = {700, 700,700,700};
        Point exp ={{0x842749DC71E8544F, 0x514E3415C90E1005, 0x9A820F0875E01A13, 0x09234DAF59273438},
					   {0x5235E8340AFEFBB6, 0x208F1A8C91710890, 0x840B6F57A304EC53, 0x3A04FCF4CD72FDA6}};//{700, 700,700,700}*G
        Point res;
		secp256k1_generator_mul(k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}

void Test_generator_mul_6(CuTest *tc){
        Scalar k = {101, 101,101,101};
        Point exp ={{0x349A00A472818766, 0xDE6FC343A529DDC1, 0x5213373198D70837, 0xEC6BD14FA8E2FB5B},
                       {0xAD4C286ED3BBD982, 0x028ED2447305351B, 0xFAB0D54DA2DAEADD, 0x2A461C37BAF43625}};//{101,101,101,101}*G
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}


void Test_generator_mul_7(CuTest *tc){
        Scalar k = {137, 100,100,100};
        Point exp ={ {0xED0669955270548A, 0x792C00A226005FC2,0x8449135B0C3D0C09 , 0x533210F4AFABD74E},
                        {0x7702D167DE9C09C3, 0xF3819AB954AB1E50, 0x234731C10D6768F6, 0xC7A955AABA76CBBF}};//{137,100,100,100}*G
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}

void Test_generator_mul_8(CuTest *tc){
        Scalar k = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xfffffffffffffffe, 0xffffffffffffffff};// order n - 1
        Point exp ={ {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                        {0x63B82F6F04EF2777, 0x02E84BB7597AABE6, 0xA25B0403F1EEF757, 0xB7C52588D95C3B9A}};
        Point res;
		secp256k1_generator_mul(k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}


void Test_generator_mul_9(CuTest *tc){
        Scalar k = {0xBFD25E8CD0364166, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF}; //order n + 25
        Point exp ={ {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49},
                        {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010} };
        Point res;
		secp256k1_generator_mul(k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}

void Test_generator_mul_10(CuTest *tc){
        Scalar k = {1, 2, 3, 4};
        Point exp ={ {0xA103B5E4937A62DD, 0xB1A1A19D87AC52F5, 0x7D29A027D305B1F9, 0xE75010603E253C46},
         				{0x629856CC38AA1D1A, 0x188FF68F4EFDD8D9, 0x317C39233F752C20, 0x63DAF0B554057290} };
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y"); 
}

void Test_generator_mul_11(CuTest *tc){
        Scalar k = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Point exp ={ {0x15714AA4B56606AF, 0x6B4A22095F894F47, 0x5F9E3DF9F69D7F35, 0x9166C289B9F905E5},
         				{0x1099AF98499255E7, 0x94E214F06C93FD09, 0xCFF9E16B66D809BE, 0xF181EB966BE4ACB5}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y"); 

}

void Test_generator_mul_12(CuTest *tc){
        Scalar k = {0x402da1732fc9bebe, 0x4551231950b75fc4, 1, 0 };//ffffffffffffffff - order n
        Point exp ={ {0x15714AA4B56606AF, 0x6B4A22095F894F47, 0x5F9E3DF9F69D7F35, 0x9166C289B9F905E5},
         				{0x1099AF98499255E7, 0x94E214F06C93FD09, 0xCFF9E16B66D809BE, 0xF181EB966BE4ACB5}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y"); 

}

void Test_generator_mul_13(CuTest *tc){
        Scalar k = {0x402da1722fc9baee, 0x4551231950b75fc4, 1, 0}; //p -n
        Point exp ={ {0x65E902417E7AF914, 0xBC3B5224BCDD4B4B, 0x5C0B8B853B6939AA, 0xB42B34A974823871 },
         				{0x936138086AC129E9, 0x87404DCA2F648560, 0x7FA170896D939C3B, 0xC1064CE5DFB9E024}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y"); 

}

void Test_generator_mul_14(CuTest *tc){
        Scalar k = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Point exp ={ {0x65E902417E7AF914, 0xBC3B5224BCDD4B4B, 0x5C0B8B853B6939AA, 0xB42B34A974823871 },
         				{0x936138086AC129E9, 0x87404DCA2F648560, 0x7FA170896D939C3B, 0xC1064CE5DFB9E024}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y"); 
}

void Test_generator_mul_15(CuTest *tc){
        Scalar k = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xfffffffffffffffe, 0xffffffffffffffff};//n-1
        Point exp ={ {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC },
         				{0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");         
}

void Test_generator_mul_16(CuTest *tc){
        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point exp ={ {0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a },
         				{0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");         
}

void Test_generator_mul_17(CuTest *tc){
        Scalar k = {0x8F643232DD1B2F45, 0x06C76E9617C917DF, 0x8E8212A8D001FA2F, 0xBE958E7C2CF53555};
        Point exp ={ {0xDE6F16004425F630, 0x6B7C284F42777941, 0x4623A201C0BA8FCB, 0x485B7911BDDC1841 },
         				{0x743AFF5DF16FF4FE,0x42C52DBDC160DADD,0x50DDE4DA872FD9E8,0x00B3906863E416D1}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");         


}

void Test_generator_mul_18(CuTest *tc){
        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point exp ={ {0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a },
                        {0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");         

}

void Test_generator_mul_19(CuTest *tc){
        Scalar k = {0x0, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point exp ={ {0x55BA44045BFC16A5, 0x87981736082C416C, 0x1BCBC6B505AD7AAF, 0xBF26E545FCD77D76},
                        {0x3BDE5E5940680D06, 0x1A716D33B129C664, 0xC5E29CB5A16DA775, 0x345DD848AC31807E}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");     

}

void Test_generator_mul_20(CuTest *tc){
        Scalar k = {0x35db29a206321725,0,0,0};
        Point exp ={ {0x432990D34DB0A38A, 0xEF7F847693AA51AE, 0xB802EEFF511EA530, 0x0D6E6A89A30CD122},
                        {0xBB3C60F0973B528C, 0x9B8D9D51156B63F8, 0x511498A93BEC1213, 0x8104A89209EBB999}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");     
}


void Test_generator_mul_21(CuTest *tc){ 
        Scalar k = {0xc2c2529eb3399b3c,0x377f8d82f883816f,0x358a73ec4cda12d9,0xf412548fa1f37eac};
        Point exp ={ {0x52b465135504e4ff, 0x97d573e36ed4385f, 0x72808056ee1e53f4, 0x74f1ce3c6ef778d6},
                        {0xd127a2980b361248, 0x7a8a2d551742bf50, 0x3aa92456dca573e0, 0xa416475ada0fd256}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");  

}


void Test_generator_mul_22(CuTest *tc){ 
        Scalar k = {0x2a26a877a58eabd5,0x0e3a8e80117f2dc3,0x9c0f6c9528ab8379,0x255bf055824c2907};
        Point exp ={ {0x002b28f4bf894477, 0x1dfa93a9285b2f4f, 0xa02640eb88cb0cfd, 0x4f83a657a0ced2b1},
                        {0xccaa9b5070c81633, 0x3e7be1ab6af1d6ca, 0xfb5c05a28b88b074, 0x9e1c64324941d002}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");  

}


void Test_generator_mul_23(CuTest *tc){  
        Scalar k = {0x98667f65db5f321a,0xb5584a8c2222519d,0x3b030056141d8837,0x4ec93408ab2fa6a9};
        Point exp ={ {0xc88923705f74ebe3, 0x0bc5ad357953ce83, 0x925ed15291736225, 0x34da6a5fe7e64ea7},
                        {0xe3597b1c29e91d01, 0xda517498d863708a, 0xd93a09e9ec7f98d0, 0xea775f9faa9a41e0}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");  

}


void Test_generator_mul_24(CuTest *tc){  
        Scalar k = {0xdf940462c4a9ed4e,0x5830f5d6dddb38c9,0xd0c1784e0b1347a2,0x05a44f99903ef13c};
        Point exp ={{0x66631d7c87fa6b09, 0xea7fb259af59d80f, 0xa3b4f953c203dae6, 0x827bbf04097867c2},
                       {0x2e6693e32d6f7566, 0x89befd00d4990a7b, 0xefc0d777f026b087, 0x842a5d53da72e8d9}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");  

}


void Test_generator_mul_25(CuTest *tc){   
        Scalar k = {0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450};
        Point exp ={{0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                       {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}


void Test_generator_mul_26(CuTest *tc){
     Scalar k = {0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF};
     //s gets internally reduced to 0x14551231950b75fc4402da1732fc9bebe without affecting the original scalar
     Point  p;
     Point exp = {{0x15714AA4B56606AF,0x6B4A22095F894F47,0x5F9E3DF9F69D7F35,0x9166C289B9F905E5},
                     {0x1099AF98499255E7,0x94E214F06C93FD09,0xCFF9E16B66D809BE,0xF181EB966BE4ACB5}};
     secp256k1_generator_mul(k, &p);
     scalarEq(exp.x, p.x, "p.x != exp.x");
     scalarEq(exp.y, p.y, "p.y != exp.y");  
}

void Test_generator_mul_27(CuTest *tc){
     Scalar k = {0x402da1732fc9bebe, 0x4551231950b75fc4, 1};//0x14551231950b75fc4402da1732fc9bebe
     Point  p;
     Point exp = {{0x15714AA4B56606AF,0x6B4A22095F894F47,0x5F9E3DF9F69D7F35,0x9166C289B9F905E5},
                     {0x1099AF98499255E7,0x94E214F06C93FD09,0xCFF9E16B66D809BE,0xF181EB966BE4ACB5}};
     secp256k1_generator_mul(k, &p);
     scalarEq(exp.x, p.x, "p.x != exp.x");
     scalarEq(exp.y, p.y, "p.y != exp.y");  
}


void Test_generator_mul_28(CuTest *tc){
     Scalar k = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
     //k == n -> undefined behavior because s is not automatically reduced mod n: n%n=0
     Point  p;
     Point exp = {{0,0,0,0},{0,0,0,0}};
     secp256k1_generator_mul(k, &p);
     CuAssert(tc, "", exp.x[0] != p.x[0]);      
     CuAssert(tc, "", exp.x[1] != p.x[1]);   
     CuAssert(tc, "", exp.x[2] != p.x[2]);      
     CuAssert(tc, "", exp.x[3] != p.x[3]);      
     CuAssert(tc, "", exp.y[0] != p.y[0]);      
     CuAssert(tc, "", exp.y[1] != p.y[1]);   
     CuAssert(tc, "", exp.y[2] != p.y[2]);      
     CuAssert(tc, "", exp.y[3] != p.y[3]);      
   
}


void Test_generator_mul_29(CuTest *tc){
     Scalar k = {0, 0, 0, 0}; //0*G -> undefined? or result = G?
     Point  p;
     Point exp = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
     secp256k1_generator_mul(k, &p);
     CuAssert(tc, "", exp.x[0] != p.x[0]);      
     CuAssert(tc, "", exp.x[1] != p.x[1]);   
     CuAssert(tc, "", exp.x[2] != p.x[2]);      
     CuAssert(tc, "", exp.x[3] != p.x[3]);      
     CuAssert(tc, "", exp.y[0] != p.y[0]);      
     CuAssert(tc, "", exp.y[1] != p.y[1]);   
     CuAssert(tc, "", exp.y[2] != p.y[2]);      
     CuAssert(tc, "", exp.y[3] != p.y[3]);  
}

void Test_generator_mul_30(CuTest *tc){
     Scalar k = {0xBFD25E8CD0364142, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n+1
     Point  p;
     Point exp = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
     secp256k1_generator_mul(k, &p);
     scalarEq(exp.x, p.x, "p.x != exp.x");
     scalarEq(exp.y, p.y, "p.y != exp.y");      
}


void Test_generator_mul_31(CuTest *tc){
     Scalar k = {0,0,0,0x0FFFFFFFFFFFFFFF};
     Point  p;
     Point exp = {{0x4DDE2837A3D3F5D5,0x24A57B5865FFE641,0x76C36C3E00CE0549,0x8A342ECD31232055},
     				 {0x8DF92078D3E41E1B,0x6D9E52275389C032,0xA82D7CC580222E0A,0x1EF8189771D704AF}};
     secp256k1_generator_mul(k, &p);
     scalarEq(exp.x, p.x, "p.x != exp.x");
     scalarEq(exp.y, p.y, "p.y != exp.y"); 
}


void Test_generator_mul_32(CuTest *tc){
		 Scalar k = {0,0,0xFFFFFFFFFFFFFFFF,0};
		 Point  p;
		 Point exp = {{0x3371D350150E96FE,0xB05892D6C6A46FBF,0x8BE659471C770FB5,0x0B00592A587731CA},                             
		  				 {0x36746F41DFFF09A0,0x43F2829888C191AA,0x1D536E704748CFFB,0x6BDC9456D4D089CD}};
		 secp256k1_generator_mul(k, &p);
		 scalarEq(exp.x, p.x, "p.x != exp.x");
		 scalarEq(exp.y, p.y, "p.y != exp.y"); 
}

void Test_generator_mul_33(CuTest *tc){
     Scalar k = {0,0,0xFFFFFFFFFFFFFFFF,0x0FFFFFFFFFFFFFFF};
     Point  p;
     Point exp = {{0x2C0402C2BA51D4EE,0x8E46F1D66DF34FFF,0xC0DBCA779584BEBB,0xF9CDDDA817150CEB},
     				 {0xE36EE91E4C9AA276,0x3300C29EF2E73BE9,0x4DD3481BDF98E16B,0xE68409628925B679}};

     secp256k1_generator_mul(k, &p);
     scalarEq(exp.x, p.x, "p.x != exp.x");
     scalarEq(exp.y, p.y, "p.y != exp.y"); 
}




void Test_point_mul_1(CuTest *tc){  
        Scalar k = {0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G
        Point exp ={ {0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                                   {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};
        Point res;
		secp256k1_point_mul(&p, k, &res);  ;    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");

}




void Test_point_mul_2(CuTest *tc){

        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G
        Point exp ={ {0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a },
                                   {0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
        Point res;
		secp256k1_point_mul(&p, k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");
}

void Test_point_mul_3(CuTest *tc){
 
        Scalar k = {0x0, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G

        Point exp ={ {0x55BA44045BFC16A5, 0x87981736082C416C, 0x1BCBC6B505AD7AAF, 0xBF26E545FCD77D76},
                        {0x3BDE5E5940680D06, 0x1A716D33B129C664, 0xC5E29CB5A16DA775, 0x345DD848AC31807E}};
        Point res;
		secp256k1_point_mul(&p, k, &res);    
        scalarEq(exp.x, res.x, "exp.x != res.x");
        scalarEq(exp.y, res.y, "exp.y != res.y");

}







void Test_point_mul_asign_1(CuTest *tc){
        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42}; 
        Point exp ={{0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a},
                       {0xF2EE187E9C582BA6, 0xBC11A1DF38855ED6, 0xFA9E77237716103A, 0x2CD470243453A299}};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
        			   {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//input: G
		secp256k1_point_mul_asign(&p,k);    
        scalarEq(exp.x, p.x, "exp.x != p.x");
        scalarEq(exp.y, p.y, "exp.y != p.y");
}

void Test_point_mul_asign_2(CuTest *tc){
        Scalar k = {0x0, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G
        Point exp ={ {0x55BA44045BFC16A5, 0x87981736082C416C, 0x1BCBC6B505AD7AAF, 0xBF26E545FCD77D76},
                                   {0x3BDE5E5940680D06, 0x1A716D33B129C664, 0xC5E29CB5A16DA775, 0x345DD848AC31807E}};
		secp256k1_point_mul_asign(&p,k);    
        scalarEq(exp.x, p.x, "exp.x != p.x");
        scalarEq(exp.y, p.y, "exp.y != p.y");
}


void Test_point_mul_asign_3(CuTest *tc){
        Scalar k = {0x35db29a206321725,0,0,0};
        Point exp = {{0x432990D34DB0A38A, 0xEF7F847693AA51AE, 0xB802EEFF511EA530, 0x0D6E6A89A30CD122}, 
        				 {0xBB3C60F0973B528C, 0x9B8D9D51156B63F8, 0x511498A93BEC1213, 0x8104A89209EBB999}};
        Point p = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                         {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};// G
		secp256k1_point_mul_asign(&p,k); 
        scalarEq(exp.x, p.x, "exp.x != p.x");
        scalarEq(exp.y, p.y, "exp.y != p.y");
}


 

void Test_point_mul_asign_4(CuTest *tc){
        Scalar k = {0x35db29a206321724, 0xe774e7f9a47e2c1f, 0x6a94f8114701e7c7, 0x18e14a7b6a307f41};
        Point exp = {{0x15B6102F43228506, 0x2E4EB529ED776E92, 0x10DAE4C62A4520DD, 0x4D696DF0B0F1C4C1},
                         {0x97A110D0A2682360, 0xDE221EA11AE3A483, 0x0769C4B534C00831, 0xD9C5BF1AC94B5C7F}};
        Point p = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                         {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//G
		secp256k1_point_mul_asign(&p,k); 
        scalarEq(exp.x, p.x, "exp.x != p.x");
        scalarEq(exp.y, p.y, "exp.y != p.y");        
}


void Test_point_mul_asign_5(CuTest *tc){
        Scalar k = {2, 0, 0 ,0};
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G
        Point p = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
		secp256k1_point_mul_asign(&p,k); 
        scalarEq(exp.x, p.x, "exp.x != p.x");
        scalarEq(exp.y, p.y, "exp.y != p.y");        

}




void Test_point_mul_asign_6(CuTest *tc){
        Scalar k = {7, 0, 0 ,0};
		Point exp ={{0x842749DC71E8544F, 0x514E3415C90E1005, 0x9A820F0875E01A13, 0x09234DAF59273438},
					   {0x5235E8340AFEFBB6, 0x208F1A8C91710890, 0x840B6F57A304EC53, 0x3A04FCF4CD72FDA6}};//{700, 700,700,700}*G
		Point p ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
		secp256k1_point_mul_asign(&p,k); 
        scalarEq(exp.x, p.x, "exp.x != p.x");
        scalarEq(exp.y, p.y, "exp.y != p.y");        
}




void Test_is_point_on_curve_1(CuTest *tc){
        Point p = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};
        int exp = 0;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "p is not on curve",exp,res); 
}
void Test_is_point_on_curve_2(CuTest *tc){
        Point p = {{0x9808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "p is on curve",exp,res); 
}


void Test_is_point_on_curve_3(CuTest *tc){
        Point p ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};
        int exp = 0;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "p is not on curve",exp,res); 
}

void Test_is_point_on_curve_4(CuTest *tc){
        Point p ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0xF2E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "p is on curve",exp,res); 
}

void Test_is_point_on_curve_5(CuTest *tc){
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
        int exp = 0;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "G is not on curve",exp,res); 
}

void Test_is_point_on_curve_6(CuTest *tc){
        Point p ={{0, 0, 0, 0}, 
                     {0xEECB4B6FBA9360DC, 0x38ED44E3932A7179, 0x0727CD69B4A7333D, 0x8F537EEFDFC1606A}}; 
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "is on curve",exp,res); 
}


void Test_is_point_on_curve_7(CuTest *tc){
        Point p ={{0, 0, 0, 0}, 
                     {0x1134B48F456C9B53, 0xC712BB1C6CD58E86, 0xF8D832964B58CCC2, 0x70AC8110203E9F95}};
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        CuAssertIntEquals_Msg(tc, "is on curve",exp,res); 
}

void Testsecp256k1_calculate_y_coordinates_from_x_1(CuTest *tc){
        Scalar x = {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49};
        Scalar exp_y = {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        scalarEq(exp_y, odd, "y != exp_y");
}

void Testsecp256k1_calculate_y_coordinates_from_x_2(CuTest *tc){
        Scalar x = {0x4DDE2837A3D3F5D5,0x24A57B5865FFE641,0x76C36C3E00CE0549,0x8A342ECD31232055};
        Scalar exp_y = {0x8DF92078D3E41E1B,0x6D9E52275389C032,0xA82D7CC580222E0A,0x1EF8189771D704AF};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        scalarEq(exp_y, odd, "y != exp_y");
}

void Testsecp256k1_calculate_y_coordinates_from_x_3(CuTest *tc){
        Scalar x = {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC};
        Scalar exp_y = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};//G
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        scalarEq(exp_y, even, "y != exp_y");
}

void Testsecp256k1_calculate_y_coordinates_from_x_4(CuTest *tc){
        Scalar x = {0x842749DC71E8544F, 0x514E3415C90E1005, 0x9A820F0875E01A13, 0x09234DAF59273438};
		Scalar exp_y =  {0x5235E8340AFEFBB6, 0x208F1A8C91710890, 0x840B6F57A304EC53, 0x3A04FCF4CD72FDA6};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        scalarEq(exp_y, even, "y != exp_y");
}

 
                     
void Testsecp256k1_calculate_y_coordinates_from_x_5(CuTest *tc){
        Scalar x = {0x15714AA4B56606AF,0x6B4A22095F894F47,0x5F9E3DF9F69D7F35,0x9166C289B9F905E5};
		Scalar exp_y =  {0x1099AF98499255E7,0x94E214F06C93FD09,0xCFF9E16B66D809BE,0xF181EB966BE4ACB5};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        scalarEq(exp_y, odd, "y != exp_y");
}                     
  
 
        				                    
void Testsecp256k1_calculate_y_coordinates_from_x_6(CuTest *tc){
        Scalar x = {0x98C13CA84DB6A392, 0xC832C50E9B1EEF8A, 0xDEF2B65EE8C8B17D, 0x6D0A80195FF48CC4 };
		Scalar exp_y =  {0xA17A800BEE319F96,0xBBEAB4B55A15F295,0xEC17A721F0F0BAF8,0x6B47A61FD59BF8D0} ;
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        scalarEq(exp_y, even, "y != exp_y");
} 


void Test_secp256k1_keypair_from_private_key_1(CuTest *tc){ 
        Scalar exp_prk = {0x2a26a877a58eabd5,0x0e3a8e80117f2dc3,0x9c0f6c9528ab8379,0x255bf055824c2907};
        Point  exp_puk ={ {0x002b28f4bf894477, 0x1dfa93a9285b2f4f, 0xa02640eb88cb0cfd, 0x4f83a657a0ced2b1},
                        {0xccaa9b5070c81633, 0x3e7be1ab6af1d6ca, 0xfb5c05a28b88b074, 0x9e1c64324941d002}};
        KeyPair kp={0x2a26a877a58eabd5,0x0e3a8e80117f2dc3,0x9c0f6c9528ab8379,0x255bf055824c2907};
		secp256k1_keypair_from_private_key(&kp); 
		Point p = kp.public_key;
        scalarEq(exp_prk, kp.private_key, "exp_prk != kp.private_key");
        scalarEq(exp_puk.x, p.x, "exp_puk.x != kp.public_key.x");  
        scalarEq(exp_puk.y, p.y, "exp_puk.y != kp.public_key.y");  

}


void Test_secp256k1_keypair_from_private_key_2(CuTest *tc){  
        Scalar exp_prk = {0x98667f65db5f321a,0xb5584a8c2222519d,0x3b030056141d8837,0x4ec93408ab2fa6a9};
        Point  exp_puk ={ {0xc88923705f74ebe3, 0x0bc5ad357953ce83, 0x925ed15291736225, 0x34da6a5fe7e64ea7},
                        {0xe3597b1c29e91d01, 0xda517498d863708a, 0xd93a09e9ec7f98d0, 0xea775f9faa9a41e0}};
        KeyPair kp; 
        kp.private_key[0] = 0x98667f65db5f321a;
        kp.private_key[1] = 0xb5584a8c2222519d;
        kp.private_key[2] = 0x3b030056141d8837;
        kp.private_key[3] = 0x4ec93408ab2fa6a9;
		secp256k1_keypair_from_private_key(&kp); 
        scalarEq(exp_prk, kp.private_key, "exp_prk != kp.private_key");
        scalarEq(exp_puk.x, kp.public_key.x, "exp_puk.x != kp.public_key.x");  
        scalarEq(exp_puk.y, kp.public_key.y, "exp_puk.y != kp.public_key.y");  

}


void Test_secp256k1_keypair_from_private_key_3(CuTest *tc){  
        Scalar exp_prk = {0xdf940462c4a9ed4e,0x5830f5d6dddb38c9,0xd0c1784e0b1347a2,0x05a44f99903ef13c};
        Point  exp_puk ={{0x66631d7c87fa6b09, 0xea7fb259af59d80f, 0xa3b4f953c203dae6, 0x827bbf04097867c2},
                       {0x2e6693e32d6f7566, 0x89befd00d4990a7b, 0xefc0d777f026b087, 0x842a5d53da72e8d9}};
        KeyPair kp ={0xdf940462c4a9ed4e,0x5830f5d6dddb38c9,0xd0c1784e0b1347a2,0x05a44f99903ef13c,0,0,0,0,0,0,0,0};
		secp256k1_keypair_from_private_key(&kp); 
        scalarEq(exp_prk, kp.private_key, "exp_prk != kp.private_key");
        scalarEq(exp_puk.x, kp.public_key.x, "exp_puk.x != kp.public_key.x");  
        scalarEq(exp_puk.y, kp.public_key.y, "exp_puk.y != kp.public_key.y");  

}


void Test_secp256k1_keypair_from_private_key_4(CuTest *tc){   
        Scalar exp_prk = {0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450};
        Point  exp_puk ={{0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                       {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};
        KeyPair kp = {{0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450},{{},{}}};

		secp256k1_keypair_from_private_key(&kp); 
        scalarEq(exp_prk, kp.private_key, "exp_prk != kp.private_key");
        scalarEq(exp_puk.x, kp.public_key.x, "exp_puk.x != kp.public_key.x");  
        scalarEq(exp_puk.y, kp.public_key.y, "exp_puk.y != kp.public_key.y");  
}



