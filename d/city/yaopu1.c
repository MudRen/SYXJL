// Room: /city/yaopu1.c
// YBL 2000/07/27 

inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
�������ݳ�ҩ�̵������ң�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG
	);


	set("objects", ([
                __DIR__"npc/ping2" : 1,
	]));

	set("exits", ([
        "south" : __DIR__"yaopu",
	]));

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

