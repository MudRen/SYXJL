// Room: /d/taishan/yidao1.c

inherit ROOM;




void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ���
�������ž�װ���¼��������еĻ���������ŵ�������������Щ
Щϰ��Ľ����ˡ���·��������������������֡�
LONG
	);

	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
                "southeast" : "/d/quanzhou/qzroad1",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 2,
                "/d/city2/npc/xiaoguiz" : 1, 
                "/d/city2/npc/hai" : 1,
	]));

	set("outdoors", "taishan");
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



