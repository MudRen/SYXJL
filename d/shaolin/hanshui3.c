// hanshui3.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
�����Ǻ�ˮ�����Σ�ˮ��������������һ���������£�ͷ�����ң�
�캬�̴��������Եõĵ����㣬�ۣ�������Ѿ����˺ü��������ˣ�
����ʲô����? ���Ա߻����ż�������ˣ�����(fish)�ɡ�
    ��ʾ(gaoshi)
LONG );
        set("exits", ([ /* sizeof() == 1 */
        "south" : "/d/shaolin/matou1",
        "enter" : "/d/shaolin/diaoyuxuan",
        "west" : "/u/bsd/xiuxishi",
        ]));

        set("item_desc", ([
                "gaoshi" : HIR"�˴�������ѧ��Ǳ��,�����ûѧ���������º�Ǳ�ܽ��˸Ų�����\n\n"NOR 
        ]));
        set("coor/x",10);
        set("coor/y",100);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",100);
        set("coor/z",0);
        set("coor/x",10);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_fish", "fish");
//      add_action("do_swim", "swim");
}

/*
int do_swim()
{
        object me;
        me = this_player();
        message_vision("$N����Σ������ˮ�У��ڳ�������������\n", me);
        me->move(__DIR__"chili");
        return 1;
}*/

int do_fish()
{
        object me;
        int i, kar, cps, bb;
        me = this_player();

        if(me->is_busy())
             return notify_fail("�㻹�ǵ�����������ٷŸ˰ɣ�\n");

        if(me->query("qi")<10)
             return notify_fail("�㻹������Ϣһ�°ɣ������ǵ�һλ�ġ�\n");

        me->start_busy(3);
//      call_out("fliping",1,me);
        message_vision("$N����һ����������ڴ�ʯͷ�ϵ�����������\n", me);

        for (i=0; i<200000; i++) ;
                message_vision("$Nֻ����Ư��Ȼһ������æ��ˡ�\n",me);
        kar = me->query("kar");
        cps = me->query("cps");
        if (random(kar+cps)>((kar+cps)/10)*9) {
                message_vision("$N����һ��������\n", me);
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"��õ���0�㾭��\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",27+bb);
                        tell_object(me,"��õ���27�㾭��\n");
                }
                me->receive_damage("qi", 10);
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"��õ���0��Ǳ��\n");
                else {
                        me->set("potential",bb+13);
                        tell_object(me,"��õ���13��Ǳ��\n");
                }
//              fish = new("/u/c/ckj/npc/obj/fish1");
//              fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/5)*3) {
                message_vision("$N����һ��������\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"��õ���0�㾭��\n");
                else {
                        me->set("combat_exp",20+bb);
                        tell_object(me,"��õ���20�㾭��\n");
                }
                me->receive_damage("qi", 10);  
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"��õ���0��Ǳ��\n");
                else
                {
                        me->set("potential",bb+9);
                        tell_object(me,"��õ���9��Ǳ��\n");
                }
//              fish = new("/u/c/ckj/npc/obj/fish2");
//              fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/3)*2) {
                message_vision("$N����һ��������\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"��õ���0�㾭��\n");
                else {
                        tell_object(me,"��õ���17�㾭��\n");
                        me->set("combat_exp",17+bb);
                }
                me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"��õ���0��Ǳ��\n");
                else {
                        me->set("potential",bb+7);
                        tell_object(me,"��õ���7��Ǳ��\n");
                }
//              fish = new("/u/c/ckj/npc/obj/fish2");
//              fish->move(me);
                return 1;
        }
        else {
                me->receive_damage("qi", 10);  
                message_vision("$NʲôҲû������\n",me );
        }

        return 1;
}

