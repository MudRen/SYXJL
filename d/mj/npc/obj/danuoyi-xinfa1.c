// danuoyi.c



#include <ansi.h>

inherit ITEM;

void setup()

{}



void init()

{

        add_action("do_du", "du");

        add_action("do_du", "study");

}



void create()

{

        set_name(HIG"乾坤大挪移心法"NOR, ({ "danuoyi xinfa" ,"xinfa"}));

        set_weight(600);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "张");

                set("long",

                        "这是一张羊皮纸，上面有一些深奥的字句，似乎\n"

                        "提到一些运功及调息方法什麽的。\n");

                set("value", 6000);

                set("material", "paper");

                set("no_give", "这样东西不能给别人。\n");

                set("no_drop", "这样东西不能离开你。\n");

                set("no_sell", "这样东西不能卖。\n");

                  set("no_steal",1);

                  set("no_put",1);

                set("skill", ([

                        "name":                 "qiankundanuoyi",          

                        "exp_required": 200000,                        



                        "jing_cost":             80,                          

  

                        "difficulty":   60,                             

                                                

                ]) );

        }

}



int do_du(string arg)

{

        object me = this_player();

        object where = environment(me);

        object ob;

        mapping skill;

        int qklevel; 

        int neili_lost;



        if (!(arg=="danuoyi xinfa" || arg == "xinfa" || arg == "book"))

        return 0;



        if (me->is_busy()) {

                write("你现在正忙着呢。\n");

                return 1;

        }



        if( me->is_fighting() ) {

                write("你无法在战斗中专心下来研读新知！\n");

                return 1;

        }



        if (!id(arg)) { 

                write("你要读什么？\n");

                return 1;

        }

        if ((string)me->query("gender") == "女性" ){

                write("自古没有女人可以练乾坤大挪移的。\n");

                return 1;

        }



        if( !me->query_skill("literate", 1) ){

                write("你是个文盲，先学点文化(literate)吧。\n");

                return 1;

        }



        switch(random(3)) {

          case 0:

        message("vision", me->name() + "脸色忽青忽红，变化无端。\n", environment(me), me);

              break;

          case 1:

        message("vision", me->name() + "脸色变得阴阳交替，诡异不已。\n", environment(me), me);

              break;

          case 2:

        message("vision", me->name() + "头上冒出一柱青烟，久久不散。\n", environment(me), me);

              break;

        }

        if( (int)me->query("jing") < 15 ) {

                write("你现在过于疲倦，无法专心下来研读新知。\n");

                return 1;

        }



        qklevel = me->query_skill("danuoyi", 1);

        if( (int)me->query("combat_exp") < (int)qklevel*qklevel*qklevel/10 ) {

                write("你的实战经验不足，再怎么读也没用。\n");

                return 1;

        }

      if( me->query_skill("jiuyang-force", 1) < 150){

                write("乾坤大挪移必须结合九阳神功！\n");

                return 1;

        }



        if( me->query("combat_exp") < 200000){

                write("乾坤大挪移需要经验深厚的人练，你还太差！\n");

                return 1;

        }



        if( me->query_skill("qiankundanuoyi", 1) > 250){

                write("你已经把乾坤大挪移修到第九层了，你已经没有什么可以要证明的了！\n");

                return 1;

        }



        me->receive_damage("jing", 80);

        if( !me->query_skill("qiankundanuoyi", 1) ) {

                me->set_skill("qiankundanuoyi", 0);

write("\n");

        }

        me->improve_skill("qiankundanuoyi", (int)me->query_skill("literate", 1)/10+1);

        write("你研读乾坤大挪移心法，颇有心得。\n");

        return 1;

}



