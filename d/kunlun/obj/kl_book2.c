// kl book2.c
inherit ITEM;

void create()
{
        set_name("两仪剑谱<下卷>", ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", @LONG
这是一本深入了解两仪剑法的秘籍，一般是不会给外人的。这本书
上所写得都是昆仑剑法的精髓！适合于有一定基础的昆仑弟子。
LONG );
        set("value", 100); 
        set("unique", 1);        set("skill", ([
                "name":  "liangyi-jian",             
                "exp_required": 10000,                          
                "jing_cost":    20+random(20),             
                "difficulty":  20,          
                "max_skill": 60,                              
        ]) );
}
  
string valid_study(object me, string arg)
{
        if ( me->query_skill("literate") < 30 )  {
                notify_fail("你还是先去多识几个字吧。\n");
                return "";
        }
        if ( me->query_skill("liangyi-jian", 1) > 150 ) {
                notify_fail("这本书对你而言，实在是太肤浅了。\n");
                return "";
        }

        write("你睁大眼睛，细细地阅读「两仪剑谱」上的说明。\n");

 return "liangyi-jian";
 
}

