inherit ROOM;
 
void create()
{
        set("short", "С·");
        set("long",@LONG
����һ��С��������������Զ�����졣С��������ֲ��һЩ�һ�����
��ֻһƳ�ͷ��֣���Щ�һ�ȫ�ǰ�ɫ�ġ�
LONG );
        set("exits", ([
  "east" : __DIR__"road2",
  "west" : __DIR__"damen",
]));
        set("outdoors", "taohua");
 
        set("coor/x",60);
	set("coor/y",-210);
	set("coor/z",0);
	setup();
}