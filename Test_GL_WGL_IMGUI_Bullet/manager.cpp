#include "pch.h"
#include "manager.h"

// table of positions of characteres on texture
vec2 uvpos1[256]=
{
	 vec2(0.0f    ,0.0f), vec2(0.0f    ,1/16.0f), vec2(0.0f    ,2/16.0f), vec2(0.0f    ,3/16.0f), vec2(0.0f    ,4/16.0f), vec2(0.0f    ,5/16.0f), vec2(0.0f    ,6/16.0f), vec2(0.0f    ,7/16.0f), vec2(0.0f    ,8/16.0f), vec2(0.0f    ,9/16.0f), vec2(0.0f    ,10/16.0f), vec2(0.0f    ,11/16.0f), vec2(0.0f    ,12/16.0f), vec2(0.0f    ,13/16.0f), vec2(0.0f    ,14/16.0f), vec2(0.0f    ,15/16.0f),
	 vec2(1/16.0f ,0.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,2/16.0f), vec2(1/16.0f ,3/16.0f), vec2(1/16.0f ,4/16.0f), vec2(1/16.0f ,5/16.0f), vec2(1/16.0f ,6/16.0f), vec2(1/16.0f ,7/16.0f), vec2(1/16.0f ,8/16.0f), vec2(1/16.0f ,9/16.0f), vec2(1/16.0f ,10/16.0f), vec2(1/16.0f ,11/16.0f), vec2(1/16.0f ,12/16.0f), vec2(1/16.0f ,13/16.0f), vec2(1/16.0f ,14/16.0f), vec2(1/16.0f ,15/16.0f),
	 vec2(2/16.0f ,0.0f), vec2(2/16.0f ,1/16.0f), vec2(2/16.0f ,2/16.0f), vec2(2/16.0f ,3/16.0f), vec2(2/16.0f ,4/16.0f), vec2(2/16.0f ,5/16.0f), vec2(2/16.0f ,6/16.0f), vec2(2/16.0f ,7/16.0f), vec2(2/16.0f ,8/16.0f), vec2(2/16.0f ,9/16.0f), vec2(2/16.0f ,10/16.0f), vec2(2/16.0f ,11/16.0f), vec2(2/16.0f ,12/16.0f), vec2(2/16.0f ,13/16.0f), vec2(2/16.0f ,14/16.0f), vec2(2/16.0f ,15/16.0f),
	 vec2(3/16.0f ,0.0f), vec2(3/16.0f ,1/16.0f), vec2(3/16.0f ,2/16.0f), vec2(3/16.0f ,3/16.0f), vec2(3/16.0f ,4/16.0f), vec2(3/16.0f ,5/16.0f), vec2(3/16.0f ,6/16.0f), vec2(3/16.0f ,7/16.0f), vec2(3/16.0f ,8/16.0f), vec2(3/16.0f ,9/16.0f), vec2(3/16.0f ,10/16.0f), vec2(3/16.0f ,11/16.0f), vec2(3/16.0f ,12/16.0f), vec2(3/16.0f ,13/16.0f), vec2(3/16.0f ,14/16.0f), vec2(3/16.0f ,15/16.0f),
	 vec2(4/16.0f ,0.0f), vec2(4/16.0f ,1/16.0f), vec2(4/16.0f ,2/16.0f), vec2(4/16.0f ,3/16.0f), vec2(4/16.0f ,4/16.0f), vec2(4/16.0f ,5/16.0f), vec2(4/16.0f ,6/16.0f), vec2(4/16.0f ,7/16.0f), vec2(4/16.0f ,8/16.0f), vec2(4/16.0f ,9/16.0f), vec2(4/16.0f ,10/16.0f), vec2(4/16.0f ,11/16.0f), vec2(4/16.0f ,12/16.0f), vec2(4/16.0f ,13/16.0f), vec2(4/16.0f ,14/16.0f), vec2(4/16.0f ,15/16.0f),
	 vec2(5/16.0f ,0.0f), vec2(5/16.0f ,1/16.0f), vec2(5/16.0f ,2/16.0f), vec2(5/16.0f ,3/16.0f), vec2(5/16.0f ,4/16.0f), vec2(5/16.0f ,5/16.0f), vec2(5/16.0f ,6/16.0f), vec2(5/16.0f ,7/16.0f), vec2(5/16.0f ,8/16.0f), vec2(5/16.0f ,9/16.0f), vec2(5/16.0f ,10/16.0f), vec2(5/16.0f ,11/16.0f), vec2(5/16.0f ,12/16.0f), vec2(5/16.0f ,13/16.0f), vec2(5/16.0f ,14/16.0f), vec2(5/16.0f ,15/16.0f),
	 vec2(6/16.0f ,0.0f), vec2(6/16.0f ,1/16.0f), vec2(6/16.0f ,2/16.0f), vec2(6/16.0f ,3/16.0f), vec2(6/16.0f ,4/16.0f), vec2(6/16.0f ,5/16.0f), vec2(6/16.0f ,6/16.0f), vec2(6/16.0f ,7/16.0f), vec2(6/16.0f ,8/16.0f), vec2(6/16.0f ,9/16.0f), vec2(6/16.0f ,10/16.0f), vec2(6/16.0f ,11/16.0f), vec2(6/16.0f ,12/16.0f), vec2(6/16.0f ,13/16.0f), vec2(6/16.0f ,14/16.0f), vec2(6/16.0f ,15/16.0f),
	 vec2(7/16.0f ,0.0f), vec2(7/16.0f ,1/16.0f), vec2(7/16.0f ,2/16.0f), vec2(7/16.0f ,3/16.0f), vec2(7/16.0f ,4/16.0f), vec2(7/16.0f ,5/16.0f), vec2(7/16.0f ,6/16.0f), vec2(7/16.0f ,7/16.0f), vec2(7/16.0f ,8/16.0f), vec2(7/16.0f ,9/16.0f), vec2(7/16.0f ,10/16.0f), vec2(7/16.0f ,11/16.0f), vec2(7/16.0f ,12/16.0f), vec2(7/16.0f ,13/16.0f), vec2(7/16.0f ,14/16.0f), vec2(7/16.0f ,15/16.0f),
	 vec2(8/16.0f ,0.0f), vec2(8/16.0f ,1/16.0f), vec2(8/16.0f ,2/16.0f), vec2(8/16.0f ,3/16.0f), vec2(8/16.0f ,4/16.0f), vec2(8/16.0f ,5/16.0f), vec2(8/16.0f ,6/16.0f), vec2(8/16.0f ,7/16.0f), vec2(8/16.0f ,8/16.0f), vec2(8/16.0f ,9/16.0f), vec2(8/16.0f ,10/16.0f), vec2(8/16.0f ,11/16.0f), vec2(8/16.0f ,12/16.0f), vec2(8/16.0f ,13/16.0f), vec2(8/16.0f ,14/16.0f), vec2(8/16.0f ,15/16.0f),
	 vec2(9/16.0f ,0.0f), vec2(9/16.0f ,1/16.0f), vec2(9/16.0f ,2/16.0f), vec2(9/16.0f ,3/16.0f), vec2(9/16.0f ,4/16.0f), vec2(9/16.0f ,5/16.0f), vec2(9/16.0f ,6/16.0f), vec2(9/16.0f ,7/16.0f), vec2(9/16.0f ,8/16.0f), vec2(9/16.0f ,9/16.0f), vec2(9/16.0f ,10/16.0f), vec2(9/16.0f ,11/16.0f), vec2(9/16.0f ,12/16.0f), vec2(9/16.0f ,13/16.0f), vec2(9/16.0f ,14/16.0f), vec2(9/16.0f ,15/16.0f),
	 vec2(10/16.0f,0.0f), vec2(10/16.0f,1/16.0f), vec2(10/16.0f,2/16.0f), vec2(10/16.0f,3/16.0f), vec2(10/16.0f,4/16.0f), vec2(10/16.0f,5/16.0f), vec2(10/16.0f,6/16.0f), vec2(10/16.0f,7/16.0f), vec2(10/16.0f,8/16.0f), vec2(10/16.0f,9/16.0f), vec2(10/16.0f,10/16.0f), vec2(10/16.0f,11/16.0f), vec2(10/16.0f,12/16.0f), vec2(10/16.0f,13/16.0f), vec2(10/16.0f,14/16.0f), vec2(10/16.0f,15/16.0f),
	 vec2(11/16.0f,0.0f), vec2(11/16.0f,1/16.0f), vec2(11/16.0f,2/16.0f), vec2(11/16.0f,3/16.0f), vec2(11/16.0f,4/16.0f), vec2(11/16.0f,5/16.0f), vec2(11/16.0f,6/16.0f), vec2(11/16.0f,7/16.0f), vec2(11/16.0f,8/16.0f), vec2(11/16.0f,9/16.0f), vec2(11/16.0f,10/16.0f), vec2(11/16.0f,11/16.0f), vec2(11/16.0f,12/16.0f), vec2(11/16.0f,13/16.0f), vec2(11/16.0f,14/16.0f), vec2(11/16.0f,15/16.0f),
	 vec2(12/16.0f,0.0f), vec2(12/16.0f,1/16.0f), vec2(12/16.0f,2/16.0f), vec2(12/16.0f,3/16.0f), vec2(12/16.0f,4/16.0f), vec2(12/16.0f,5/16.0f), vec2(12/16.0f,6/16.0f), vec2(12/16.0f,7/16.0f), vec2(12/16.0f,8/16.0f), vec2(12/16.0f,9/16.0f), vec2(12/16.0f,10/16.0f), vec2(12/16.0f,11/16.0f), vec2(12/16.0f,12/16.0f), vec2(12/16.0f,13/16.0f), vec2(12/16.0f,14/16.0f), vec2(12/16.0f,15/16.0f),
	 vec2(13/16.0f,0.0f), vec2(13/16.0f,1/16.0f), vec2(13/16.0f,2/16.0f), vec2(13/16.0f,3/16.0f), vec2(13/16.0f,4/16.0f), vec2(13/16.0f,5/16.0f), vec2(13/16.0f,6/16.0f), vec2(13/16.0f,7/16.0f), vec2(13/16.0f,8/16.0f), vec2(13/16.0f,9/16.0f), vec2(13/16.0f,10/16.0f), vec2(13/16.0f,11/16.0f), vec2(13/16.0f,12/16.0f), vec2(13/16.0f,13/16.0f), vec2(13/16.0f,14/16.0f), vec2(13/16.0f,15/16.0f),
	 vec2(14/16.0f,0.0f), vec2(14/16.0f,1/16.0f), vec2(14/16.0f,2/16.0f), vec2(14/16.0f,3/16.0f), vec2(14/16.0f,4/16.0f), vec2(14/16.0f,5/16.0f), vec2(14/16.0f,6/16.0f), vec2(14/16.0f,7/16.0f), vec2(14/16.0f,8/16.0f), vec2(14/16.0f,9/16.0f), vec2(14/16.0f,10/16.0f), vec2(14/16.0f,11/16.0f), vec2(14/16.0f,12/16.0f), vec2(14/16.0f,13/16.0f), vec2(14/16.0f,14/16.0f), vec2(14/16.0f,15/16.0f),
	 vec2(15/16.0f,0.0f), vec2(15/16.0f,1/16.0f), vec2(15/16.0f,2/16.0f), vec2(15/16.0f,3/16.0f), vec2(15/16.0f,4/16.0f), vec2(15/16.0f,5/16.0f), vec2(15/16.0f,6/16.0f), vec2(15/16.0f,7/16.0f), vec2(15/16.0f,8/16.0f), vec2(15/16.0f,9/16.0f), vec2(15/16.0f,10/16.0f), vec2(15/16.0f,11/16.0f), vec2(15/16.0f,12/16.0f), vec2(15/16.0f,13/16.0f), vec2(15/16.0f,14/16.0f), vec2(15/16.0f,15/16.0f),

};

// table of sizes of characteres on texture
//vec2 uv3dsizes[256]={
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//
//};

// table of positions of characteres on 3d
//vec2 pos3d[256]={
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//	 vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f), vec2(1/16.0f ,1/16.0f),
//
//};

vec2 uvsizes(1/16.0f,1/16.0f);

text2::text2(){
	txt.clear();
	len=0;
};

text2::text2(char * t){
	len = (uint)strlen(t);
	if(len<1){
		len = 0;
		return;
	}
	txt = t;
}

text2::~text2(){

}

void text2::draw(vec4 &color, vec2 &size, vec3 &pos, vec3 &rot){

}

void text2::constructVBO(){
	quads = new vec2[len*4];
	uvs = new vec2[len*4];

	float xpos =0, ypos=0;
	for(uint i=0; i<len*4; i+=4, xpos+=0.008f){
		if (!(xpos<1.0f)){
			xpos=0;
			ypos+=0.01f;
		}
		// quads positions
		quads[i] = vec2(xpos, ypos);
		quads[i+1] = vec2(xpos, ypos+0.008f);
		quads[i+2] = vec2(xpos+0.008f, ypos);
		quads[i+3] = vec2(xpos+0.008f, ypos+0.008f);
		// quads uvs
		uvs[i]   = vec2(uvpos1[txt[i]]);
		uvs[i+1] = vec2(uvpos1[txt[i]]+vec2(0.0f, uvsizes.x));
		uvs[i+2] = vec2(uvpos1[txt[i]]+vec2(uvsizes.x, 0.0f));
		uvs[i+3] = vec2(uvpos1[txt[i]]+uvsizes);

	}

}

int drawText(const char* txt, vec2 position, vec2 size, vec4 color, vec2 rot){
	uint len = (uint)strlen(txt);

	//float xpos =0, ypos=0;
	vec2 pos = position;
	glBegin (GL_QUADS);
		glColor3fv (&color.x);
		for(uint i=0; i<len; i++, pos.x+=size.x*0.085f){
			if ((pos.x+size.x*0.08f)>1.0f){
				pos.x=position.x;
				pos.y-=size.y*0.05f+0.060f;
			}
			vec2 v;
			glTexCoord2fv(&uvpos1[txt[i]].x);
			v = (pos + vec2(0, size.y * -0.1f));
			glVertex2fv(&v.x);
			v = uvpos1[txt[i]] + vec2(uvsizes.x, 0);
			glTexCoord2fv(&v.x);
			v = pos + vec2(size.x * 0.08f, size.y * -0.1f);
			glVertex2fv(&v.x);
			v = uvpos1[txt[i]] + uvsizes.x;
			glTexCoord2fv(&v.x);
			v = pos + vec2(size.x * 0.08f, size.y * 0);
			glVertex2fv(&v.x);
			v = uvpos1[txt[i]] + vec2(0, uvsizes.y);
			glTexCoord2fv(&v.x);
			v = pos + vec2(0, size.y * 0);
			glVertex2fv(&v.x);
		}
	glEnd ();
	return len;
}


/*








*/














