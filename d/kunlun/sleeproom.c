// sleeproom.c (kunlun)



#include <ansi.h>

#include <room.h>



inherit ROOM;



void create()

{

set("short","����");

        set("long",@long

�����Ǻ�̫����谮�ĵ���С���õ��Է�����һ�������˱Ǳ���һ��ҩ

�������滹���ŵ�һ��ʮ�ֹŹֵ���Ϣ������Ƭ�̣�����������Ϣ��Ũ������

�������ء���������һ���ˣ�������������������������ǳ��ŷ��䡣��

��(window)���ǽ������š�

long);



set("item_desc", ([

"window" : "������ƣ��㲻����򿪴���͸͸����\n",

]));



set("objects",([

  "/d/kunlun/npc/zhanchun.c" :   1,

]));



set("exits", ([

"east" : __DIR__"tieqinju",

]));

setup();

}





