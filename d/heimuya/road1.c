//road1.c ����·
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
	set("long", @LONG
����һ����ʯ�����Сɽ�ڣ���������ͨ�����ϵĴ�·��.
��˵ǰ��������Ұ�޳�û�����ɾ�����
LONG
	);
        set("outdoors", "wudang");

        set("exits", ([
                "northwest" : "/d/wudang/wdroad5",
		"southeast" : __DIR__"shidao3",
//                "west" : __DIR__"linjxd1.c",
//                "east" : __DIR__"dating4",
        ]));

        set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
