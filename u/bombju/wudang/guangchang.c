// guangchang.c �㳡
// by Xiang

inherit ROOM;

void create()
{
        set("short", "�䵱�㳡");
        set("long", @LONG
        ����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص㡣
��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�ɨ��
����������������
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                "southdown" : __DIR__"shijie62",
                "north" : __DIR__"sanqingdian",
                "west"  :__DIR__"shijie7",
                "east"  :__DIR__"xiaolu",
        ]));
        set("objects", ([
            __DIR__"npc/qingshu" : 1 ,
                CLASS_D("wudang") + "/daotong" : 2]));

        set("coor/x",-50);
        set("coor/y",80);
        set("coor/z",180);
        set("coor/x",-50);
        set("coor/y",80);
        set("coor/z",180);
        set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",180);
	setup();
        replace_program(ROOM);
}
