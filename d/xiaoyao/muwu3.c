// muwu3.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����Ҳ��һ��ľ�ݣ������еİ���ʲô�򵥣�����ȴ�кܶ๤�ߣ�����
���������������������������ص�ľм��һ����֪����һ�������ļҡ�����
���ǵ��ɽ���æ���أ�������֪����������ʲô�أ�
LONG
        );

       set("exits", ([
               "north" : __DIR__"mubanlu",
       ]));
 	set("objects", ([
		__DIR__"npc/fengas": 1,
]));
      set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
