inherit ROOM;
 
void create()
{
        set("short", "С·");
        set("long",@LONG
����һ��ͨ����ɽ��С����С·���Գ������Ӳݡ��������Ǻ���������·��
������·����Ҳϡϡ����ð���˲�ѿ��������һ��Сɽ����
LONG);
        set("exits", ([
  "east"   : __DIR__"road5",
  "north"  : __DIR__"road2",
]));
        set("objects", ([
        __DIR__"npc/dushe": 4,
	]) );
        set("outdoors", "taohua");
       
 
        set("coor/x",70);
	set("coor/y",-220);
	set("coor/z",0);
	setup();
}
