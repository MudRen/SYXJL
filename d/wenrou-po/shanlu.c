// shanlu  ..angle
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��խխ��ɽ·���Ѷ��ϣ�·�Ծ����ְ����ܵĹ�ľ�ԣ�һЩ��ʯ�̳�
��С·ȴ�Ǹ���ĸ�š����������ݲ�ʯ����
LONG
        );
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        set("exits", ([
          "east" : __DIR__"shichang1",
      "west" : "/d/wudang/wdroad1", 
]));
        set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}


