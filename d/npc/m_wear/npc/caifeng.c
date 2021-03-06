// Jay 3/26/96
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老裁缝", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 60);
        set("long",
                "这位老裁缝正笑咪咪地忙著，还不时的擦一擦自己的老花眼。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
        set("max_neli",5000);
        set("jiali",50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
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
        set("combat_exp", 250000);
    
        map_skill("force","bibo-shengong");
        map_skill("parry","luoying-shenjian");
        map_skill("sword","luoying-shenjian");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("dodge","anying-fuxiang");
    
        set("attitude", "peaceful");
        
        set("inquiry", ([
        "订做衣服"  : "订做衣服可是件十分艰苦的事，要消耗人的精气和内力，你有决心和毅力吗？\n",
        "原料"  : "订做衣服可用雪蚕。。。你找到了我才能帮你订做衣服。\n",
       ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
        add_action("do_ding","ding");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "老裁缝笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来订身衣服吧。\n");
                        break;
                case 1:
                        say( "老裁缝愁眉苦脸说道：这位" + RANK_D->query_respect(ob)
                                + "，你又胖又矮，这帮不了你。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{   
     if (!(ob = present("yiluo sha", this_player())))
     {
     message("vision","这是什么！这不能用来定做服饰！\n",who);
     }
     else
     {
     who->set_temp("get_wear",1);
     destruct(ob);
     message("vision","老裁缝低头检视了一下手中的倚萝纱点了点头说：\n",who);
     write("我这儿可以定做以下服饰：\n"+
          "     丝带(belt)\n"+
          "     帽子(hat)\n"+
          "     头巾(scarf)\n"+
          "     靴子(shoes)\n"+
          "     衣服(cloth)\n");       
    say("这位"+RANK_D->query_respect(who)+"要定做什么服饰？决定了告诉我(answer)。\n");        
    }
    return 0;
}

int do_answer(string arg)
{
    object me;
    me = this_player();
    if(!(me->query_temp("get_wear") ) ){
        write("你找到原料了吗？\n");
        return 1;
    }
    
    if(!arg){
       write("你要造什么服饰？\n");
      return 1;
    }
    message("vision",me->name()+"对老裁缝轻声说了几句。\n",environment(me), ({me}) );
    switch (arg) {
      case "belt" : 
        me->delete_temp("get_wear");
        me->set_temp("wear",1);
        write("请这位"+RANK_D->query_respect(me)+"给丝带起名字吧！(ding 丝带的中文名字(使用颜色请参考help nick))\n");
        break;
      case "hat" :
        me->delete_temp("get_wear");
        me->set_temp("wear",2);
        write("请这位"+RANK_D->query_respect(me)+"给帽子起名字吧！(ding 帽子的中文名字(使用颜色请参考help nick))\n");
        break;
      case "scarf" :
        me->delete_temp("get_wear");
        me->set_temp("wear",3);
        write("请这位"+RANK_D->query_respect(me)+"给头巾起名字吧！(ding 头巾的中文名字(使用颜色请参考help nick))\n");
        break;
      case "shoes" :
        me->delete_temp("get_wear");
        me->set_temp("wear",4);
        write("请这位"+RANK_D->query_respect(me)+"给靴子起名字吧！(ding 靴子的中文名字(使用颜色请参考help nick))\n");
        break;
      case "cloth" :
        me->delete_temp("get_wear");
        me->set_temp("wear",5);
        write("请这位"+RANK_D->query_respect(me)+"给衣服起名字吧！(ding 衣服的中文名字(使用颜色请参考help nick))\n");
        break;
      default :
        message_vision(HIC "老裁缝一脸狐疑：什么服饰？\n" NOR,me);
        return notify_fail("老裁缝仔细的说：此事不可儿戏，请慎重!!\n");
    }
    return 1;
}

int do_ding(string arg)
{
    string o_name,id,w_name;
    object abc,make_time;   //生成的武器句柄
    object me;
    int cba;
    me = this_player();
    cba = me->query_temp("wear");
    switch (cba) {
      case 1 : 
          if((me->query("wear/belt")) ) {
             say("老裁缝一脸茫然：您已经有一条丝带了，还来干什么？难到不称心吗？\n");
             return 2;
          }
          if( !arg )
             return notify_fail("老裁缝认真的说：想好丝带的名称后在对我说。\n");
          sscanf(arg ,"%s" ,w_name );
          id="my belt";
          if(!w_name||!id)
             return notify_fail("什么?(使用ding 丝带的中文名字\n)");
          me->delete_temp("wear");
          o_name="倚萝纱";
          make_time=NATURE_D->game_time();
          write("老裁缝告诉你：已经做好了，客官请过目。\n");
          me->set("wear/beltname",w_name+NOR);  //武器的名称
          me->set("wear/belt",1);       //武器制造后防止再造的标志      
          me->set("wear/beltid",id);        //武器的代号
          me->set("wear/beltlv",1);     //武器等级
          me->set("wear/beltor",o_name);    //记录制造原料
          me->set("wear/beltvalue",0);          //记录武器升级已有的点数    
          me->set("wear/belttype","丝带");
          me->set("wear/belttime",make_time);
          abc=new("/d/npc/m_wear/wear/m_belt",1);    //生成新剑
          abc->move(this_player());
        break;
      case 2 :
          if((me->query("wear/hat")) ) {
             say("老裁缝一脸茫然：您已经有一顶帽子了，还来干什么？难到不称心吗？\n");
             return 2;
          }
          if( !arg )
             return notify_fail("老裁缝认真的说：想好帽子的名称后在对我说。\n");
          sscanf(arg ,"%s" ,w_name );
          id="my hat";
          if(!w_name||!id)
             return notify_fail("什么?(使用ding 帽子的中文名字\n)");
          me->delete_temp("wear");
          o_name="倚萝纱";
          make_time=NATURE_D->game_time();
          write("老裁缝告诉你：已经做好了，客官请过目。\n");
          me->set("wear/hatname",w_name+NOR);  //武器的名称
          me->set("wear/hat",1);       //武器制造后防止再造的标志      
          me->set("wear/hatid",id);        //武器的代号
          me->set("wear/hatlv",1);     //武器等级
          me->set("wear/hator",o_name);    //记录制造原料
          me->set("wear/hatvalue",0);          //记录武器升级已有的点数    
          me->set("wear/hattype","帽子");
          me->set("wear/hattime",make_time);
          abc=new("/d/npc/m_wear/wear/m_hat",1);    //生成新剑
          abc->move(this_player());
        break;
      case 3 :
          if((me->query("wear/scarf")) ) {
             say("老裁缝一脸茫然：您已经有一条头巾了，还来干什么？难到不称心吗？\n");
             return 2;
          }
          if( !arg )
             return notify_fail("老裁缝认真的说：想好头巾的名称后在对我说。\n");
          sscanf(arg ,"%s" ,w_name );
          id="my scarf";
          if(!w_name||!id)
             return notify_fail("什么?(使用ding 头巾的中文名字\n)");
          me->delete_temp("wear");
          o_name="倚萝纱";
          make_time=NATURE_D->game_time();
          write("老裁缝告诉你：已经做好了，客官请过目。\n");
          me->set("wear/scarfname",w_name+NOR);  //武器的名称
          me->set("wear/scarf",1);       //武器制造后防止再造的标志      
          me->set("wear/scarfid",id);        //武器的代号
          me->set("wear/scarflv",1);     //武器等级
          me->set("wear/scarfor",o_name);    //记录制造原料
          me->set("wear/scarfvalue",0);          //记录武器升级已有的点数    
          me->set("wear/scarftype","头巾");
          me->set("wear/scarftime",make_time);
          abc=new("/d/npc/m_wear/wear/m_scarf",1);    //生成新剑
          abc->move(this_player());
        break;
      case 4 :
          if((me->query("wear/shoes")) ) {
             say("老裁缝一脸茫然：您已经有一双靴子了，还来干什么？难到不称心吗？\n");
             return 2;
          }
          if( !arg )
             return notify_fail("老裁缝认真的说：想好靴子的名称后在对我说。\n");
          sscanf(arg ,"%s" ,w_name );
          id="my shoes";
          if(!w_name||!id)
             return notify_fail("什么?(使用ding 靴子的中文名字\n)");
          me->delete_temp("wear");
          o_name="倚萝纱";
          make_time=NATURE_D->game_time();
          write("老裁缝告诉你：已经做好了，客官请过目。\n");
          me->set("wear/shoesname",w_name+NOR);  //武器的名称
          me->set("wear/shoes",1);       //武器制造后防止再造的标志      
          me->set("wear/shoesid",id);        //武器的代号
          me->set("wear/shoeslv",1);     //武器等级
          me->set("wear/shoesor",o_name);    //记录制造原料
          me->set("wear/shoesvalue",0);          //记录武器升级已有的点数    
          me->set("wear/shoestype","靴子");
          me->set("wear/shoestime",make_time);
          abc=new("/d/npc/m_wear/wear/m_shoes",1);    //生成新剑
          abc->move(this_player());
        break;
      case 5 :
          if((me->query("wear/cloth")) ) {
             say("老裁缝一脸茫然：您已经有一件衣服了，还来干什么？难到不称心吗？\n");
             return 2;
          }
          if( !arg )
             return notify_fail("老裁缝认真的说：想好衣服的名称后在对我说。\n");
          sscanf(arg ,"%s" ,w_name );
          id="my cloth";
          if(!w_name||!id)
             return notify_fail("什么?(使用ding 衣服的中文名字\n)");
          me->delete_temp("wear");
          o_name="倚萝纱";
          make_time=NATURE_D->game_time();
          write("老裁缝告诉你：已经做好了，客官请过目。\n");
          me->set("wear/clothname",w_name+NOR);  //武器的名称
          me->set("wear/cloth",1);       //武器制造后防止再造的标志      
          me->set("wear/clothid",id);        //武器的代号
          me->set("wear/clothlv",1);     //武器等级
          me->set("wear/clothor",o_name);    //记录制造原料
          me->set("wear/clothvalue",0);          //记录武器升级已有的点数    
          me->set("wear/clothtype","衣服");
          me->set("wear/clothtime",make_time);
          abc=new("/d/npc/m_wear/wear/m_cloth",1);    //生成新剑
          abc->move(this_player());
        break;
      default :
        return notify_fail("什么?\n");
    }
    w_name = replace_string(w_name, "$BLK$", BLK);
    w_name = replace_string(w_name, "$RED$", RED);
    w_name = replace_string(w_name, "$GRN$", GRN);
    w_name = replace_string(w_name, "$YEL$", YEL);
    w_name = replace_string(w_name, "$BLU$", BLU);
    w_name = replace_string(w_name, "$MAG$", MAG);
    w_name = replace_string(w_name, "$CYN$", CYN);
    w_name = replace_string(w_name, "$WHT$", WHT);
    w_name = replace_string(w_name, "$HIR$", HIR);
    w_name = replace_string(w_name, "$HIG$", HIG);
    w_name = replace_string(w_name, "$HIY$", HIY);
    w_name = replace_string(w_name, "$HIB$", HIB);
    w_name = replace_string(w_name, "$HIM$", HIM);
    w_name = replace_string(w_name, "$HIC$", HIC);
    w_name = replace_string(w_name, "$HIW$", HIW);
    w_name = replace_string(w_name, "$NOR$", NOR);
    return 1;
}
