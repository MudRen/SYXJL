#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�᷿");
        set("long", @LONG
����һ���򵥵����᷿������ֻ��һ��ľ����һ��ľ���ζ��ѡ�����
�����ݻ���ȴ�Ǵ�ɨ�ĸɸɾ�����һ����Ⱦ��������һ��������ɫ��������
����վ�ڴ�ǰ�������ؿ��Ŵ��⡣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"wannian",
                ]));
        set("objects",([
                CLASS_D("wudang") + "/xiaosong" : 1,
                ]));
        create_door("west", "ľ��", "east", DOOR_CLOSED);
        set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",100);
	setup();
}
int valid_leave(object me,string dir)
{
	me=this_player();
	if(me->query_temp("xiaosong") && objectp(present("song qingshu",environment(me))) 
		&& dir=="west")
	return notify_fail("��������ס�㣬�ȵ������첻�������������һ\n");
	return ::valid_leave(me,dir);
}
