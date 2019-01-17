// wangding.c ��ľ����

#include <ansi.h>

inherit ITEM;

int do_put(string);
int do_suck(string);
//int come_duchong(object, object);
int ok_suck(object, object);

void create()
{
	set_name(YEL"��ľ����"NOR, ({"shenmu wangding", "wangding", "ding"}));
        set("long","����һ���������ߴ�С��ľ���������ɫ���������Ǿ�ϸ��ľ�ʼ���\n"
	"����ľ��֮������ԼԼ�ķ�����˿��\n");
       	set("unit", "��");
	set("weight", 130);
        set("no_drop", "�������������뿪�㡣\n");

}

void init()
{
        add_action("do_put","put");
        add_action("do_suck", "suck");
}

int do_put(string arg)
{
        object ob, env, me = this_player();
        string what, where;

        if( !arg || sscanf(arg, "%s in %s", what, where) != 2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( !(where == "shenmu wangding" || where == "wangding" || where == "ding") )
                return 0;

        if( what == "all" ) {
                write("����һ��һ�����ɡ�\n");
                return 1;
        }

        if( !objectp(ob = present(what, me)) )
                return notify_fail("������û������������\n");

        if( ob->query("id") != "xiang" )
                return notify_fail("��ľ����ֻ����������ץ���档\n");

        if( ob->query("name") != "��ȼ����" )
                return notify_fail("�㻹���Ȱ����ȼ�ɡ�\n");

        message_vision("$N��һ֧��ȼ��������ľ�����С�\n", me);
        destruct(ob);

        env = environment(this_object());

        if( (int)env->query("duchong") > 0 ) {
		remove_call_out("come_duchong");
//		call_out("come_duchong", 10 + random(20), env, this_object());
        }

        return 1;
}

int do_suck(string arg)
{
        object me = this_player();

        int lvl, lvl2;

        if( !arg || ( arg != "blood" ) )
                return 0;

        if( query("amount") < 1 )
                return notify_fail("��Ҫ��ʲô��\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("���ֵط�����������\n");

        if( me->is_fighting() )
                return notify_fail("ս���в���������\n");

        if( me->query_skill_mapped("poison") != "xingxiu-dugong" )
                return notify_fail("�㲻�����޶������ն��ʣ���ô��������\n");

        if( me->query_skill_mapped("force") != "beiming-zhenqi" )
                return notify_fail("�㲻�˱�ڤ�����������أ����ķ���������\n");

        if( me->query("qi") < 70 || me->query("jing") < 70 )
                return notify_fail("������״�����ѣ���ЪϢһ����ɡ�\n");

        if( me->query("neili") < 50 )
                return notify_fail("������������\n");

        add("amount", -1);
        me->receive_damage("qi", 20 + random(20));
        me->receive_damage("jing", 20 + random(20));
        me->add("neili", -10 - random(10));

        message_vision("$N���ƽ�ѪҺ��ס����ϥ�˹�����ѪҺ���������ڡ�\n", me);

   // need bingcan after 150 level
        if( lvl < 150 )
                me->improve_skill("huagong-dafa", 5 + random(me->query("con")));

        me->improve_skill("chousui-zhang", 1 + random(me->query("int")));

  // i set the punishment in /adm/daemons/natured.c 
  // give punishment if query("apply/xx_du") < 2 * (lvl - 60)
        
        if( me->query("apply/xx_du") < me->query("con") * lvl )
                me->add("apply/xx_du", 5 + random(10));

        return 1;
}
/*
int come_duchong(object env, object ob)
{
        object obj;
  
        if( environment(ob) != env )
                return 1;

        if( env->query("duchong") < 1 )
                return 1;

        switch( random(3) ) {
        case 0:
                obj = new("/d/xingxiu/npc/scorpion");
                break;
        case 1:
                obj = new("/d/xingxiu/npc/wugong");
                break;
        case 2:
                obj = new("/d/xingxiu/npc/spider");
                break;
        }

        message_vision(HIR"�����õ����������죬ȴ��һֻ$N���˹�������$N�ŵ�����ɢ������������������ľ�����Ӷ��µĿ������ȥ���㲻�ٳ�����\n"NOR, ob, env);
        env->add("duchong", -1);
        obj->move(ob);
        call_out("ok_suck", 5 + random(10), ob, obj);

        if( (int)env->query("duchong") < 1 )
                call_out("refresh_duchong_room", 60 + random(60), env);

        return 1;
}

*/
void refresh_duchong_room(object env)
{
        env->set("duchong", env->query("max_duchong"));
}

int ok_suck(object ob, object obj)
{
        message_vision("����һ�����" + ob->query("name") + "���" + obj->query("name") + "������һ̲ŧѪ��\n", ob);
        set("long", "һֻ�������ɵİ���ɫСľ��, ľ��֮������������˿�����������ͭǮ���Բ�ף���ֻ��������һ̲Ѫ��һ�εδӿ��е�������\n");
        set("amount", 100 + random(100));
        destruct(ob);

        return 1;
}