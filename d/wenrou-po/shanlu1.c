// shanlu1  ..angle
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��խխ��ɽ·���Ѷ��ϣ�·�Ծ����ְ����ܵĹ�ľ�ԣ�һЩ��ʯ�̳�
��С·ȴ�Ǹ���ĸ�ţ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  "eastup" : __DIR__"shanlu2", 
  "southdown" : __DIR__"shichang", 
  "westdown" : __DIR__"shichang1", 
]));
        set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
}


