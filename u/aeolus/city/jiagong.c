// Room: /d/city/jiagong.c

#include <room.h>
inherit ROOM;
int potential_lv(int exp);

void create()
{
        set("short", "����ӹ���");
        set("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ��һ
����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц������Կ������
������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��
LONG
        );
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg","1");
        
        set("item_desc", ([
                "sign" : "��������ȱ���֣������Ӷһ���̹����ɻ
work     ��ʼ������ 
sleep    ���ˣ�˯���ɡ�\n",
        ]));
        set("exits", ([
                "north" : "/d/city/dongmen",
        ]));
        set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_work", "work");
        add_action("do_sleep", "sleep");
}

int do_work(string arg)
{
        object me;
        int jing_cost, qi_cost;

        me = this_player();
        jing_cost = 600 / (int)me->query("int");
        qi_cost = 500 / (int)me->query("int");
        
        if ( me->query_temp("jiagong") == 0 ) 
        { 
          if ((int)this_player()->query("combat_exp", 1) <= 2000 )
          {
           write ("�㿪ʼ����ع���......\n");  
           call_out("wait", 10, this_player());
           me->receive_damage("jing", jing_cost );
           me->receive_damage("qi", qi_cost );
           me->set_temp("jiagong",1);
           me->start_busy(6);
          }
          else
           write ("�ϰ�˵�������������Ѿ��㹻,�㻹����ذɡ�\n");
               return 1;
        } 
        
        if ( !me->query_temp("jiagong") || (me->query_temp("jiagong") == 1 ))
                return notify_fail("���Ѿ���ʼ�����ˡ�\n"); 
}

void wait(object me)
{
        object obn;
        int bonus;
        
        me = this_player();
           me->set("combat_exp",me->query("combat_exp")+random(10));
        bonus = (int)me->query("potential");
        bonus = bonus - (int)me->query("learned_points");
        bonus = bonus + random(3);
        if ( bonus > potential_lv((int)me->query("combat_exp")) )
        bonus = potential_lv((int)me->query("combat_exp"));
        bonus += (int)me->query("learned_points");
        me->set("potential", bonus );
        write ("������Ĺ������ڽ����ˣ�����Ҳ�۵İ�����\n");  
        obn = new("/clone/money/silver");
        obn->set_amount(1);
        obn->move(me);
        me->delete_temp("jiagong");
        me->set_temp("rent_paid",1);
}

int do_sleep(string arg)
{
    int rnd;
        object me = this_player();
        object where = environment(me);
        if (arg) return 0;
        if (me->query("family/family_name") == "ؤ��") return 0;
        if (me->is_busy())
              { write("����һ������δ��ɣ�\n"); return 1;}
        if (me->is_fighting() )
              { write("ս����˯��������ѽ��\n"); return 1;}
        if ( !me->query_temp("rent_paid")) return 0;
        if (me->query_temp("sleeped"))
              { write("���˯��һ��, ��˯�������к�����! \n");return 1;}
        message_vision("$N�����½���һ�ɣ���ʼ˯����\n",me);
        rnd=random(100/me->query_con()+2);
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        me->set_temp("block_msg/say", 1);
        me->set_temp("block_msg/vision", 1);
        me->set_temp("block_msg/sound", 1);
        me->set_temp("sleeped",1);
        me->disable_player("<˯����>");
        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        return 1;
}
protected void wakeup(object me,object where)
{
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
        me->set_temp("block_msg/all",1);
        me->move(environment(me));
        me->delete_temp("block_msg");
        if ( userp(me) && (!me->query("food") || !me->query("water")) ){
                message("vision",me->name()+"һ��������������������ģ�û�а�㾫��\n",environment(me),({me}));
                write("��һ��������������������ģ�û�а�㾫�񡣿�����Ҫȥ�ҵ�Ե��ˣ�\n");
        }else{
                message("vision",me->name()+"һ����������������ػ��һ�½�ǡ�\n",environment(me),({me}));
                write("��һ��������ֻ���������档�ûһ���ˡ�\n");
                me->set("qi",    me->query("eff_qi"));
                me->set("jing",  me->query("eff_jing"));
        }  
        call_out("del_sleeped", 5, me);
        if (where)
                where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
        me->delete_temp("rent_paid"); 
}

protected void del_sleeped(object me)
{
        if (objectp(me))
                me->delete_temp("sleeped");
}

int valid_leave(object me, string dir)
{
        if ( dir == "north" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}

