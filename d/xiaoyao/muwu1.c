// muwu1.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long", @LONG
������һ�䲻���ľͷ���ӣ�������ȸ��С����ؾ�ȫ��������ֻ����
������ذ��ż����Ҿߣ�����Ҳ���Ե���ôС��
LONG
        );

       set("exits", ([
               "north" : __DIR__"xiaodao5",
       ]));
 	set("objects", ([
		__DIR__"npc/kanggl": 1,
]));
      set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}