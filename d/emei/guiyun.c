#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ƹ�");
        set("long", @LONG
������ǧ���ֵĹ��Ƹ�Ҳ�Ƕ����ɵĲؾ����Ƕ����ɵ��صأ�����
��˳���������ܣ�����Ϸ����˸�ʽ�������鼮���з𾭵ĺ��书�ģ���
���ɵĵ��Ӿ�������ͬ��������˽��ġ�����Ҫ�ǵù黹��
LONG    );

        set("exits", ([
		"westdown" : __DIR__"dcmen",
               ])); 
        set("objects",([
               __DIR__"npc/obj/jing1" : 1,
               __DIR__"npc/obj/jing2" : 1,
             ]));  
        set("coor/x",0);
	set("coor/y",40);
	set("coor/z",120);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",120);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}