// hanshui3.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "钓鱼台");
        set("long", @LONG
这里是汉水中下游，水流见缓。江边有一老翁身穿蓑衣，头带斗笠，
嘴含烟袋正悠闲自得的钓着鱼，哇！他身边已经掉了好几根大鱼了！
还发什么呆啊? 你旁边还放着几根钓鱼杆，快点钓(fish)吧。
    告示(gaoshi)
LONG );
        set("exits", ([ /* sizeof() == 1 */
        "south" : "/d/shaolin/matou1",
        "enter" : "/d/shaolin/diaoyuxuan",
        "west" : "/u/bsd/xiuxishi",
        ]));

        set("item_desc", ([
                "gaoshi" : HIR"此处钓鱼后快学完潜能,如果做没学完就做别的事后潜能降了概不负责。\n\n"NOR 
        ]));
        set("coor/x",10);
        set("coor/y",100);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",100);
        set("coor/z",0);
        set("coor/x",10);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_fish", "fish");
//      add_action("do_swim", "swim");
}

/*
int do_swim()
{
        object me;
        me = this_player();
        message_vision("$N不顾危险跳入水中，在池里游了起来…\n", me);
        me->move(__DIR__"chili");
        return 1;
}*/

int do_fish()
{
        object me;
        int i, kar, cps, bb;
        me = this_player();

        if(me->is_busy())
             return notify_fail("你还是等鱼饵换好了再放杆吧！\n");

        if(me->query("qi")<10)
             return notify_fail("你还是先休息一下吧，生命是第一位的。\n");

        me->start_busy(3);
//      call_out("fliping",1,me);
        message_vision("$N拿起一根钓鱼杆坐在大石头上钓起鱼来……\n", me);

        for (i=0; i<200000; i++) ;
                message_vision("$N只见鱼漂猛然一动，急忙提杆…\n",me);
        kar = me->query("kar");
        cps = me->query("cps");
        if (random(kar+cps)>((kar+cps)/10)*9) {
                message_vision("$N钓到一条红鳟鱼\n", me);
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"你得到了0点经验\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",27+bb);
                        tell_object(me,"你得到了27点经验\n");
                }
                me->receive_damage("qi", 10);
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"你得到了0点潜能\n");
                else {
                        me->set("potential",bb+13);
                        tell_object(me,"你得到了13点潜能\n");
                }
//              fish = new("/u/c/ckj/npc/obj/fish1");
//              fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/5)*3) {
                message_vision("$N钓到一条白鲳鱼\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"你得到了0点经验\n");
                else {
                        me->set("combat_exp",20+bb);
                        tell_object(me,"你得到了20点经验\n");
                }
                me->receive_damage("qi", 10);  
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"你得到了0点潜能\n");
                else
                {
                        me->set("potential",bb+9);
                        tell_object(me,"你得到了9点潜能\n");
                }
//              fish = new("/u/c/ckj/npc/obj/fish2");
//              fish->move(me);
                return 1;
        }
        if (random(kar+cps)>((kar+cps)/3)*2) {
                message_vision("$N钓到一条大鲤鱼\n", me);
                bb=(int)me->query("combat_exp");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"你得到了0点经验\n");
                else {
                        tell_object(me,"你得到了17点经验\n");
                        me->set("combat_exp",17+bb);
                }
                me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                if(me->query("combat_exp")>=50000)
                        tell_object(me,"你得到了0点潜能\n");
                else {
                        me->set("potential",bb+7);
                        tell_object(me,"你得到了7点潜能\n");
                }
//              fish = new("/u/c/ckj/npc/obj/fish2");
//              fish->move(me);
                return 1;
        }
        else {
                me->receive_damage("qi", 10);  
                message_vision("$N什么也没钓到。\n",me );
        }

        return 1;
}

