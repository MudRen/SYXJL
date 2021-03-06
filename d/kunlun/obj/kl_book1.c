// kl book.c

inherit ITEM;

void create()
{
        set_name("两仪剑谱<上卷>", ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", @LONG
                
这是一本介绍两仪剑法的入门书，两仪剑法是铁琴先生自创的剑法！
易学易懂，这本书虽然只介绍了昆仑剑法初入门的功夫，但是用来防身已
经算不错了，适合初学者。
                
LONG );
        set("value", 100); 
        set("unique", 1);        set("skill", ([
                "name":"liangyi-jian", 
                "exp_required": 100,  
                "jing_cost"   :  20+random(20),  
                "difficulty" :  20,      
                "max_skill"  :  30, 
                                                                               
              ]) );
        setup();
}

string valid_study(object me, string arg)
{
        if ( me->query_skill("literate") < 10 )  {
                notify_fail("你还是先去多识几个字吧。\n");
                return "";
        }
        if ( me->query_skill("liangyi-jian", 1) > 30 ) {
                notify_fail("这本书对你而言，实在是太肤浅了。\n");
                return "";
        }

        write("你睁大眼睛，细细地阅读「两仪剑谱」上的说明。\n");

 return "liangyi-jian";
 
}


