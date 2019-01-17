// buxiang

#include <weapon.h>
#include <ansi.h>
string query_autoload() { return 1 + "OK"; }

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("������",({ "bu zhenxiang", "xiang"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_steal_from", 1);
                set("value", 1);
                set("unique", 1);
                set("rigidity", 8);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -10);
                set("treasure",1);
                set("wield_neili", 1500);
                set("wield_maxneili", 2000);
                set("wield_str", 32);
        }
        init_sword(1000);
        setup();
}

int init()
{
        add_action("do_jia", "add");
}

int do_jia(string arg1)
{
        object ob, me, obj, *all;
        string sb, arg;
        int i;

        me = this_player();
        all = users();


        if( !arg1 || arg1=="" )
                return notify_fail("ʲô��\n");

        if( !(sscanf(arg1, "%s %s", sb, arg)==2) )
                return notify_fail("ʲô��\n");

        if( sscanf(arg1, "%s %s", sb, arg)==2 )
        for(i=0; i<sizeof(all); i++)
        {
                if( sb == (string)all[i]->query("id") )
                ob = all[i];
        }
        if( !ob ) ob = (present(sb, environment(me)));

        if (!ob) return notify_fail("ʲô��\n");
        if (!arg) return notify_fail("ʲô��\n");

        if ( arg == "shen" ){
                ob->add("shen", 1000);
        }

        else if ( arg == "per" ){
                ob->add("per", 1);
        }

        else if ( arg == "str" ){
                ob->add("str", 1);
        }

        else if ( arg == "con" ){
                ob->add("con", 1);
        }

        else if ( arg == "dex" ){
                ob->add("dex", 1);
        }

        else if ( arg == "panshi" ){
                ob->delete("betrayer");
        }

        else if ( arg == "lv" ){
                ob->add("weapon/lv", 1);
        }

        else if ( arg == "kar" ){
                ob->add("kar", 1);
        }

        else if ( arg == "-shen" ){
                ob->add("shen",-1000);
        }

        else if ( arg == "neili" )
        {
                ob->add("max_neili", random(10) + 40);
        }

        else if ( arg == "age" )
        {
                ob->add("mud_age", 1000);
        }

        else if ( arg == "-age" )
        {
                ob->add("mud_age", -1000);
        }

        else if ( arg == "jingli" )
        {
                ob->add("max_jingli", random(10) + 40);
        }

        else if ( arg == "exp" )
        {
                ob->add("combat_exp", random(100) + 900);
        }

        else if ( arg == "potential" )
        {
                ob->add("potential", random(10) + 40);
        }

        else if ( arg == "score" )
        {
                ob->add("score", random(10) + 10);
        }

        else if ( arg == "huanhun" )
        {
                 obj=new("/clone/misc/huanhun-dan");
                obj->move(ob);
        }

        else if ( arg == "buxiang" ){
                obj=new("/d/mr/npc/obj/buxiang");
                obj->move(ob);
        }
        else if ( arg == "gold" ){
                obj=new("/clone/money/gold");
                obj->move(ob);
        }

        else if ( arg == "xuelian" ){
                obj=new("/d/honghua/xuelian");
                obj->move(ob);
        }

        else if ( arg == "thousand-cash" ){
                obj=new("/clone/money/thousand-cash");
                obj->move(ob);
        }

        else if ( arg == "hanzhu" ){
                obj=new("/d/npc/m_weapon/tan/item/hanzhu");
                obj->move(ob);
        }

        else if ( arg == "jinmu" ){
                obj=new("/d/npc/m_weapon/tan/item/jinmu");
                obj->move(ob);
        }

        else if ( arg == "shenmu" ){
                obj=new("/d/npc/m_weapon/tan/item/shenmu");
                obj->move(ob);
        }

        else if ( arg == "stone" ){
                obj=new("/d/npc/m_weapon/tan/item/stone");
                obj->move(ob);
        }

        else if ( arg == "dan" ){
                obj=new("/clone/medicine/dan");
                obj->move(ob);
        }

        else if ( arg == "fengshen" ){
                obj=new("/u/rhxlwd/bak/fengshen");
                obj->move(ob);
        }

        else if ( arg == "putizi" ){
                obj=new("/d/shaolin/obj/puti-zi");
                obj->move(ob);
        }


        else if ( arg == "fumodao" ){
                obj=new("/d/shaolin/obj/fumo-dao");
                obj->move(ob);
        }

        else if ( arg == "jingangzhao" ){
                obj=new("/d/shaolin/obj/jingang-zhao");
                obj->move(ob);
        }

        else if (
                arg == "literate" ||
                arg == "bushidao" ||
                arg == "force" ||
                arg == "liusheng-xinyinliu" ||
                arg == "unarmed" ||
                arg == "parry" ||
                arg == "taoism" ||
                arg == "dodge" ||
                arg == "blade" ||
                arg == "sword" ||
                arg == "falchion" ||
                arg == "beiming-shengong" ||
                arg == "lingbo-weibu" ||
                arg == "xixing-dafa" ||
                arg == "liuyang-zhang" ||
                arg == "zhemei-shou" ||
                arg == "anran-xiaohunzhang" ||
                arg == "yunu-xinjing" ||
                arg == "yunu-shenfa" ||
                arg == "xuantie-jianfa" ||
                arg == "dugu-jiujian" ||
                arg == "dugu-jianjue" ||
                arg == "liumai-shenjian" ||
                arg == "shenghuo-shengong" ||
                arg == "qingyunwu" ||
                arg == "jiuyang-force" ||
                arg == "qiankundanuoyi" ||
                arg == "throwing" ||
                arg == "hubo" ||
                arg == "qimen-dunjia" ||
                arg == "hand" ||
                arg == "qimen-wuxing" ||
                arg == "finger" ||
                arg == "beiming-zhenqi" ||
                arg == "tianshan-zhang" ||
                arg == "taiji-quan" ||
                arg == "taiji-jian" ||
                arg == "zhaixinggong" ||
                arg == "tianluo-diwang" ||
                arg == "huanhua-jian" ||
                arg == "strike" ||
                arg == "cuff" ||
                arg == "xuantian-wuji" ||
                arg == "liangyi-jian" ||
                arg == "fliangyi-jian" ||
                arg == "qishang-quan" ||
                arg == "taiji-shengong"||
                arg == "zixia-shengong"||
                arg == "kongrong-canggong"||
                arg == "duanjia-jian"||
                arg == "wuyue-jianfa"||
                arg == "angui-zhang"||
                arg == "bushidao"||
                arg == "falchion"


                )
        {
                ob->improve_skill(arg, 13654);
        }
        else
                return notify_fail("ʲô��\n");

        return 1;
}


