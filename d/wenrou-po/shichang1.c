 // shichang 1 ..angle
inherit ROOM;
#include <ansi.h>;
int potential_lv(int exp);

void create()
{
        set("short", "��ʯ��");
        set("long",
"�����Ǹ��ܴ�Ĳ�ʯ������������Ŀ�����������Ѿ����µĴ��
СС����ʯ����ɽ�ԣ�������ʯ����վ�ھ�ʯ���������ô���ʯͷ������
�ܶ���˽�ʯ�鿸�ڼ�������������͡���˵��Щʯͷ����������ɽ����
��������"+HIR+"�������֡�"+NOR+"����ģ�����˵��"+HIR+"�������֡�"+NOR+"������ʦ̫����һ����
�亱�еľ�ɫ���ˣ�\n ");
        set("no_clean_up", 0);
        set("exits", ([
  "eastup" : __DIR__"shanlu1", 
  "east" : __DIR__"shichang",
  "west" : __DIR__"shanlu",
        ]));
        set("objects", ([
                __DIR__"npc/caoliu" : 1,
                __DIR__"obj/jushi" : 1,
        ]));
        set("coor/x",20);
        set("coor/y",-40);
        set("coor/z",0);
        set("coor/x",20);
        set("coor/y",-40);
        set("coor/z",0);
        set("coor/x",20);
        set("coor/y",-40);
        set("coor/z",0);
        set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}

void init()
{
         add_action("do_za","��");
}

int do_za(string arg)
{
        object me;
        int i, bonus;

        me=this_player();
        if( !arg && arg !="ʯͷ" && arg !="ju shi" && arg !="shi" ) return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ�������ء�\n");

         if (me->query("combat_exp") >= 25000)
                  return notify_fail("���Ѿ�����ͨ����ʯ�����Ӿ����ˡ�\n");
        if( !present("hammer", this_player()) ) {
 tell_object(me,"\nֻ����������ƺݺݵ����ʯ����ȥ��ֻ�������ꡱһ�������ǹ������������ʱ�㷢����Χ���˺�����͵͵���֣�\n");
                me -> receive_damage ("qi",10) ;
                me->start_busy(2);
                return notify_fail("���ǸϽ��Ҹ��������ɣ�\n");
                }

        if(me->query_temp("stonework")<6) {
                message_vision(HIY"$N������������Բ�˸첲��׼ʯͷ�ݺݵ�����������\n"NOR,me);
                i = (int)this_player()->query("str", 1) + random(1000);
                    if(i<250) {
                        tell_object(me,"����һ���ӱ������������ڿ��л���һ�������Ļ��ߣ�Ȼ���ʵ�����������ƨ���ϣ�\n");
                        me -> receive_damage ("qi",10 + random(5));
                        return 1;
                        }
                me->start_busy(1);
                tell_object(me,"ž�һ����һ��С��ʯ�Ӿ�ʯ�ϵ���������������Ĺ�����û�а׷��\n");
                me -> receive_damage ("qi",15 + random(10)) ;
        bonus = (int)me->query("potential");
        bonus = bonus - (int)me->query("learned_points");
        bonus = bonus + random(4) +3;
        if ( bonus > potential_lv((int)me->query("combat_exp")) )
        bonus = potential_lv((int)me->query("combat_exp"));
        bonus += (int)me->query("learned_points");
        me->set("potential", bonus );
/*
                if( !me->query("potential") || me->query("potential") <300 ){
                 me->add("potential",random(4)+3);}
*/
                if( !me->query("combat_exp") || me->query("combat_exp") <5000 ){
                  me->add("combat_exp",random(6)+6);}
                me->add_temp("stonework",1);

                return 1;
                } 
        return notify_fail(HIW"��һ�������˰ɣ���ЪЪ�ˣ���ȥ�Ҳ��������˰ɡ�\n"NOR);
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("stonework") && (dir == "east" || dir == "eastup"|| dir == "west") && present("cao liu", environment(me)) && living(present("cao liu", environment(me))) ) {                                                    message_vision(HIM"�������һ�����������վס��Ҫ���߾Ͱ���Ĺ����Ƚ��ˣ����Ҳ���
��ѽ����\n"NOR,this_player());
                return notify_fail("");
                }
        return ::valid_leave(me, dir);
}


int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
} 

