// Room: /d/shaolin/fumoquan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;
int potential_lv(int exp);

void create()
{
        set("short", "��շ�ħȦ");
        set("long", @LONG
���ô������������ϸ����˸�������һ�˵Ĵ󶴣��и�����
¶����ɫɮ��һ�ǣ��ƺ�ס�����ˡ�������һƬ���ƺ�����Ĵ�
��ͺͺ�ģ��ƺ������ܴ����������´�ݲ�����
LONG
        );

        set("exits", ([
                "out" : __DIR__"qyping",
        ]));

        set("objects",([
                CLASS_D("shaolin") + "/du-nan" : 1,
                CLASS_D("shaolin") + "/du-e" : 1,
                CLASS_D("shaolin") + "/du-jie" : 1,
        ]));
        setup();
}

void init()
{       
        mapping mine;

//      mine = this_player()->query("family");

        if( interactive( this_player()) ) {
                if ( mapp(mine = this_player()->query("family")) && mine["family_name"] == "������" 
                && mine["generation"] == 36 ) return;
                else
        message_vision(HIR "ͻȻ�侢���ݺᣬ��������������������͵ع�����˲�����
����һ�����Եı��У��糤ì����˰������������ֱ���$N��ͷ��
�أ�������Ҫ�����̶�����$NһƳ�䣬����������ɮ�־�������
��֮�У���ȫ���ֱ���$N������$N��������������֮�̺����Ͻ�
ħ�󷨵Ľ�շ�ħȦ��\n\n" NOR, this_player());
        }


        if ( (int)this_player()->query("potential") - (int)this_player()->query("learned_points") > (int)potential_lv((int)this_player()->query("combat_exp")) )
       {
     this_player()->set("potential",(int)this_player()->query("learned_points") + potential_lv((int)this_player()->query("combat_exp")) );
        }
/*
        if ( mapp(mine)
        && mine["generation"] > 2 
        && mine["family_name"] == "������" 
        && this_player()->query("qi") < 300 ) 
*/
        if ( this_player()->query("combat_exp") < 10000 || this_player()->query("max_neili") < 300 )
        {
                message_vision(HIR "$N��һ����ɽ������ľ������У���ʱ���˳�ȥ !\n" NOR, this_player());
        this_player()->move("/d/shaolin/qyping");
        this_player()->unconcious();
        }

}

int valid_leave(object me, string dir)
{

        if( dir == "out" && present("puti zi", me) )
        {
                return notify_fail("����˵��: ���ܴ����������뿪��ħȦ !\n");
        }
        me->delete_temp("fighter");
        if(me->query_temp("marks/no_putizi"))
                me->delete_temp("marks/no_putizi");

        return ::valid_leave(me, dir);
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}

