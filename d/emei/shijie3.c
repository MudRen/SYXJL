#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", RED"�⽣ʯ"NOR);
	set("long",
"�����Ƕ�üɽ����������"RED"�⽣ʯ"NOR"����ʯ�׵��Ա�����һ��޴��ʯ\n"
"�飬�����ÿ���"RED"���⽣ʯ��"NOR"�������֡�"RED"�⽣ʯ"NOR"���Ա�վ�ż�������Ů\n"
"�����ڼ��������ˡ�\n"
         );
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie1",
  "northup" : __DIR__"gchang",
           ]));

        set("objects",([
            __DIR__"npc/shoushan" : 2,
               ])); 	

	set("coor/x",-60);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-60);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-60);
	set("coor/y",-70);
	set("coor/z",10);
	setup();
}

int valid_leave(object me, string dir)
{
        
        if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
             && objectp(present("shoushan dizi", environment(me))) && 
              dir == "northup" && (string)me->query("family/family_name") != "������")
                return notify_fail("��ɽ����˵: ���ҷ�����֮�أ�ʩ����Ҫ��ɽ��������\n");
        return ::valid_leave(me, dir);
}