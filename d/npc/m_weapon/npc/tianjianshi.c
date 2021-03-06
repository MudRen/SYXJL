// npc: /d/xingxiu/npc/afanti.c

// Jay 3/26/96

// modify by five

#include <ansi.h>

inherit NPC;



int do_weapon();

object creat_weapon();



void create()

{

        set_name("欧冶子", ({ "ouye zi", "zi" }) );

        set("nickname", RED "赤心剑胆" NOR );

          set("title", "玄天派开山祖师" );
        set("gender", "男性" );

        set("age", 60);

        set("long",     

            "他头上包着头巾，三缕长髯飘洒胸前，面目清瘦但红晕有光，\n"

            "二目炯炯有神，烁烁闪着竟似是凛凛的剑光，浑身似乎都包围\n"

            "在一股剑气之中。\n");

        set("str", 25);

        set("dex", 20);

        set("con", 17);

        set("int", 30);

        set("shen_type", 0);

        set("max_neli",5000);

        set("jiali",50);



        set_skill("unarmed", 100);

        set_skill("dodge", 100);

        set_skill("claw",200);

        set_skill("jiuyin-baiguzhao",200);

        set_skill("force",150);

        set_skill("sword",150);

        set_skill("bibo-shengong",100);

        set_skill("luoying-shenjian",100);

        set_skill("parry",90);

        set_skill("anying-fuxiang",100);

        set_temp("apply/attack", 50);

        set_temp("apply/defense", 50);

        set_temp("apply/damage",50);



//          create_family("玄天派",1,"弟子");


        set("combat_exp", 250000);

        set("score",0);

        

        map_skill("force","bibo-shengong");

        map_skill("parry","luoying-shenjian");

        map_skill("sword","luoying-shenjian");

        map_skill("claw","jiuyin-baiguzhao");

        map_skill("dodge","anying-fuxiang");



        

        set("attitude", "peaceful");

        

        set("inquiry", ([

            "铸剑"  : "铸剑可是件十分艰苦的事，要消耗人的精气和内力，你有决心和毅力吗？\n",

            "原料"  : "铸剑可用千年玄铁。。。你找到了我才能帮你铸剑。\n",

       ]) );

            set("no_get",1);

        setup();

        set("chat_chance", 3);

        set("chat_msg", ({

             "欧冶子抚剑而歌：巨阙神兵兮，人铸就。盖世宝剑兮，配英雄！\n",

             "欧冶子低头沉吟，似乎在思考什么。\n"

             "欧冶子叹了一口气：神兵配英雄，可英雄。。。。。。\n"

       }) );

        carry_object("/clone/misc/cloth")->wear();

        carry_object("/clone/weapon/changjian")->wield();

}



void init()

{

        ::init();

        add_action("do_answer","answer");

}





int accept_object(object who, object ob)

{       



        if((who->query("weapon/make")) ){

                say("欧冶子一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");

       call_out("destrory",0,ob);

                return 2;

        }

        switch ((string)ob->query("name") ) 

        {

                case "千年神木": 

                        who->set_temp("or",1);

                        who->set_temp("get_orc",1);

                        break;

                case "海底金母":

                        who->set_temp("or",2);

                        who->set_temp("get_orc",1);

                        break;

                case "寒丝羽竹": 

                        who->set_temp("or",3);

                        who->set_temp("get_orc",1);

                        break;

                default :

                        message("vision","这是什么！这不能用来打造兵器！",who);

                        return 2;

        }

        message("vision","欧冶子低头检视了一下手中的"+(string)ob->query("name")+

                        "点了点头说：\n",who);



        write("我这儿可以打造以下兵器：\n"+

              "     剑(jian)\n"+

              "     刀(dao)\n"+

              "     棍(gun)\n"+

              "     杖(staff)\n"+

              "     棰(hammer)\n"+

              "     鞭(whip)\n");               

        say("这位"+RANK_D->query_respect(who)+"要造什么兵器？决定了告诉我(answer)。\n");

       call_out("destrory",0,ob);

        return 2;



}



int do_answer(string arg)

{

        object me,w_or;

        me = this_player();

        if(!(me->query_temp("get_orc") ) ){

                write("你找到原料了吗？\n");

                return 0;

        }

        

        if(!arg){

           write("你要造什么兵器？\n");

          return 0;

        }

        message("vision",me->name()+"对欧冶子轻声说了几句。\n",environment(me), ({me}) );

        switch (arg) {

          case "jian" :

                me->add_temp("sword",1);

                write("带着原料去找侍剑吧!\n");

                message("vision","去吧！"+me->name()+"!\n",me);

                break;

          case "dao" :

                me->add_temp("blade",1);

                write("带着原料去找侍刀吧!\n");

                message("vision","去吧！"+me->name()+"!\n",me);

                break;

          case "gun" :

                me->add_temp("club",1);

                write("带着原料去找侍棍吧!\n");

                message("vision","去吧！"+me->name()+"!\n",me);

                break;

          case "staff" :

                me->add_temp("staff",1);

                write("带着原料去找侍杖吧!\n");

                message("vision","去吧！"+me->name()+"!\n",me);

                break;

          case "whip" :

                me->add_temp("whip",1);

                write("带着原料去找侍鞭吧!\n");

                message("vision","去吧！"+me->name()+"!\n",me);

                break;

          case "hammer" :

                me->add_temp("hammer",1);

                write("带着原料去找侍棰吧!\n");

                message("vision","去吧！"+me->name()+"!\n",me);

                break;



          default :

                message_vision(HIC "欧冶子一脸狐疑：什么兵器？\n" NOR,me);

                return notify_fail("欧冶子仔细的说：此事不可儿戏，请慎重!!\n");

        }

        switch ( me->query_temp("or") ) {

          case 1:

                w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);

                w_or->move(me);

                message_vision(HIC "欧冶子给了$N一块千年神木\n" NOR, me);

                break;

          case 2:

                w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);

                w_or->move(me);

                message_vision(HIC "欧冶子给了$N一块海底金母\n" NOR, me);

                break;

          case 3:

                w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);

                w_or->move(me);

                message_vision(HIC "欧冶子给了$N一块寒丝羽竹\n" NOR, me);

                break;

        }

        me->delete_temp("or");

        return 1;

}

void destrory(object ob)

{

      destruct(ob);

     return;

}

