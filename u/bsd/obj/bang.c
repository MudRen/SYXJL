//bang.c 榜
//by bsd 13/12/2000

#include <ansi.h>
inherit ITEM;

int do_read(string arg);
void create()
{
      

  set_name(HIY "★"HIR"光"HIY"★"HIR"荣"HIY"★"HIR"榜"HIY"★" NOR, ({ "guangrong bang","bang" }) );
        
        set("unit", "本");
        set("long", "这是一张用来纪录江湖成名人物的光荣榜，
风风雨雨，岁月流逝，红榜依旧。而上的
名字却换了一代又一代。只见上面写着：
                    
            "HIW"好好学习 天天向上"NOR"

             一："CYN"江湖十大"YEL"富豪"NOR"
             二："CYN"十大"HIR"杀人狂魔"NOR"
             三："CYN"十大"HIC"武林高手"NOR"
             四："CYN"江湖十大"RED"剑客"NOR"
             五："CYN"十大"HIR"神拳无敌"NOR"
             六: "CYN"十大"HIM"博学鸿儒"NOR"
             七："CYN"江湖十大"GRN"刀客"NOR"
             八："CYN"十大"BLU"轻功高手"NOR"

你可以用(read 标号)来翻看记载。\n");
        
        set("material","steel");
        set_weight(10000000);
        setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
       string str;
	if(!arg||arg=="") 
	   return notify_fail("你要阅读哪一项排行？\n");
switch(arg)
	{
		case "一": arg ="rich";			break;
		case "二": arg = "pker";		break;
		case "三": arg = "exp";			break;
		case "四": arg = "sword";		break;
		case "五": arg = "unarmed";		break;
		case "六": arg = "literate";	break;
		case "七": arg = "blade";		break;
		case "八": arg = "dodge";		break;
		default : arg = "none";			break;
	}
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");

	return 1;
}
