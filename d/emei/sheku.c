inherit ROOM;

void create()
{
	set("short", "�߿�");
	set("long", @LONG
��������߿��ˣ�����һƬ�ڰ�������ͻȻ�俴����Χ���Ƕ��߷���
���۾����ÿֲ��������߶�����������˻˻���������˸е����顣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shkrkou",
  "north" : __DIR__"shkjtou",
]));
	set("no_clean_up", 0);

	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",110);
	setup(); 
}
	
                      
int valid_leave(object me, string dir)
{
        if (objectp(present("snake", environment(me))) && 
                dir == "north" )
                return notify_fail("���ߵ�ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
