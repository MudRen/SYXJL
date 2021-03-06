// xinshi.c
// by hate.
#include <ansi.h>
inherit NPC;

mapping *names=({
           
      (["name":                "伐木道长",
       "where" :              "武当派",]),  
      (["name":                "宋远桥",
       "where" :              "武当派",]),  
      (["name":                "俞莲舟",
       "where" :              "武当派",]),  
      (["name":                "张松溪",
       "where" :              "武当派",]), 
      (["name":                "殷梨亭",
       "where" :              "武当派",]), 
      (["name":                "谷虚道长",
       "where" :              "武当派",]), 
      (["name":                "空空儿",
       "where" :              "丐帮",]),
      (["name":                "林震南",
       "where" :              "福威镖局",]),
      (["name":                "殷野王",
       "where" :              "明教",]),
      (["name":                "苏梦清",
       "where" :              "峨嵋派",]),
      (["name":                "李明霞",
       "where" :              "峨嵋派",]),
      (["name":                "贝锦仪",
       "where" :              "峨嵋派",]),
      (["name":                "方碧琳",
       "where" :              "峨嵋派",]),
      (["name":                "黄蓉",
       "where" :              "桃花岛",]),        
      (["name":                "林平之",
       "where" :              "扬州城",]),  
      (["name":                "快活三",
       "where" :              "丐帮",]),        
      (["name":                "赵狗儿",
       "where" :              "丐帮",]), 
      (["name":                "程药发",
       "where" :              "扬州城",]),        
      (["name":                "谭友纪",
       "where" :              "扬州城",]),        
      (["name":                "程玉环",
       "where" :              "扬州城",]),        
      (["name":                "钱眼开",
       "where" :              "扬州城",]),        
      (["name":                "唐楠",
       "where" :              "扬州城",]),        
      (["name":                "本因",
       "where" :              "天龙寺",]),        
      (["name":                "欧阳锋",
       "where" :              "白驼山派",]),        
      (["name":                "李教头",
       "where" :              "白驼山派",]),        
      (["name":                "张妈",
       "where" :              "白驼山派",]),        
      (["name":                "杨过",
       "where" :              "古墓派",]),        
      (["name":                "小龙女",
       "where" :              "古墓派",]),        
      (["name":                "林朝英",
       "where" :              "古墓派",]),        
      (["name":                "铁匠",
       "where" :              "扬州城",]),        
      (["name":                "陆冠英",
       "where" :              "扬州城",]),        
      (["name":                "左全",
       "where" :              "丐帮",]),        
      (["name":                "程英",
       "where" :              "桃花岛",]),
      (["name":                "冯默风",
       "where" :              "桃花岛",]),     
      (["name":                "陆乘风",
       "where" :              "扬州城",]),        
      (["name":                "欧阳克",
       "where" :              "扬州城",]),        
      (["name":                "曲灵风",
       "where" :              "桃花岛",]),
      (["name":                "梅超风",
       "where" :              "桃花岛",]),     
      (["name":                "黄药师",
       "where" :              "桃花岛",]),     
       (["name":                "恶毒子",
       "where" :              "星宿派",]),
       (["name":                "阿紫",
       "where" :              "星宿派",]),
       (["name":                "天狼子",
       "where" :              "星宿派",]),
       (["name":                "慧洁尊者",
       "where" :              "少林派",]),
       (["name":                "慧色尊者",
       "where" :              "少林派",]),
       (["name":                "慧如尊者",
       "where" :              "少林派",]),
       (["name":                "慧真尊者",
       "where" :              "少林派",]),
       (["name":                "玄难大师",
       "where" :              "少林派",]),
       (["name":                "玄苦大师",
       "where" :              "少林派",]),
       (["name":                "澄寂",
       "where" :              "少林派",]),
       (["name":                "澄坚",
       "where" :              "少林派",]),
       (["name":                "澄净",
       "where" :              "少林派",]),
       (["name":                "澄行",
       "where" :              "少林派",]),
       (["name":                "澄灭",
       "where" :              "少林派",]),
      (["name":                "史青山",
       "where" :              "扬州守将",]),
      (["name":                "采花子",
       "where" :              "星宿派",]), 
      (["name":                "殷天正",
       "where" :              "明教",]),
      (["name":                "周颠",
       "where" :              "明教",]),
      (["name":                "说不得",
       "where" :              "明教",]),
      (["name":                "张中",
       "where" :              "明教",]),
      (["name":                "辛然",
       "where" :              "明教",]),
     (["name":                "范遥",
       "where" :              "明教",]),
     (["name":                "清法比丘",
       "where" :              "少林派",]),
     (["name":                "清无比丘",
       "where" :              "少林派",]),
       });   

string ask_job();

void create()
{
        set_name("老板", ({ "boss" }));
        set("title", HIC"驿站老板"NOR);
        set("gender", "男性");
        set("age", 43);
        set("str", 27);
        set("dex", 26);
        set("long", "这人一身牧人穿着。\n");
        set("combat_exp", 400000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("whip", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 20);

        set("max_qi", 900);
        set("neili", 900); 
        set("max_neili", 900);
        set("jiali", 20);
       set("inquiry", 
                ([
                        "送信" : (: ask_job :),
                        "job" : (: ask_job :),
                ]));


       setup();
       carry_object("/d/city/obj/cloth")->wear();
}

string ask_job()
{
        object me;
        object ob;
       mapping target;
        ob=this_player();
        me=this_object();
       if (ob->query_temp("hate_songxin"))
                return ("你不是已经领了送信的任务吗？还不快去做。\n");
        if (ob->query("combat_exp")>=100000)
                     return ("我看你的武功已有相当的功底了，就不用在我这里干事了，去干点别的什么吧。\n");
       if (ob->query("combat_exp")<10000)
                     return ("你的功夫还不够啊，送信可是很危险的事，我可不敢交给你这任务。\n");
 
       target = names[random(sizeof(names))];
       ob->delete_temp("songxin_ok");
       ob->delete_temp("hate_songxin_late");

       ob->set_temp("hate_songxin",1);
       ob->start_busy(5 + random(2));
       ob->set_temp("songxin_target_name", target["name"]);
       ob->set_temp("songxin_where", target["where"]);
switch(random(3)) {
        case 0:
        message_vision("$N悄悄把$n拉到一旁，低声说道，你把这封密函火速送到「"+ob->query_temp("songxin_where")+"」"
"的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
       message_vision("$N交给$n一封密函。\n",me,ob);
        ob=new("/u/hate/songxin/hate_letter");
        ob->start_busy(4 + random(4));
        break;
        case 1:
        message_vision("$N点了点头，说道，我这里正好有封信，你去把它送到「"+ob->query_temp("songxin_where")+"」"
"的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
        message_vision("$N交给$n一封信。\n",me,ob);
        ob=new("/u/hate/songxin/hate_letter");
        ob->start_busy(4 + random(4));
        break;
        case 2:
        message_vision("$N微微一笑，从怀中掏出一封信，说道，你赶紧把它送到「"+ob->query_temp("songxin_where")+"」"
"的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
       message_vision("$N交给$n一封信。\n",me,ob);
        ob=new("/u/hate/songxin/hate_letter"); 
        ob->start_busy(4 + random(4));        break;
        }
        ob->move(this_player());
      return "速度要快！不要丢俺的老脸哟！！";
}
