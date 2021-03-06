// quest_list.c
// make by Luky
// 任务分为 寻,杀,送,找
// 寻: 找寻物品，交回发任务的npc
// 杀: 杀死npc
// 送: 送物品到另一个的npc
// 找: 发任务的npc叫玩家去找寻在指定npc身上的指定物品,然后交回

inherit F_CLEAN_UP;

void init_var();
void do_add_list_name(string arg);
void do_add_list_type(string arg);
void do_add_list_time(string arg);
void do_add_list_exp(string arg);
void do_add_list_pot(string arg);
void do_add_list_target(string arg);
void do_add_list_desc(string arg);
void do_add_list_object(string arg);
int check_legal_arg(string arg);

static mapping item = ([
        "name"           :  "",
        "quest_type"     :  "",
        "quest_time"     :  0,
        "exp"            :  0,
        "pot"            :  0,
        "time"           :  0,
        "quest_target"   :  "",
        "quest_desc"     :  "",
        "quest_objects"  :  "",
]);

string *type = ({ "寻", "杀", "送", "找" });

int main(object me,string arg)
{
        string owner;
        int lvl;

        me = this_player();
        if( !arg ) {
                if ( me->query_temp("add_quest") ) {
                        write( "您现在正在始添加"+me->query_temp("add_quest/owner")+"."+ me->query_temp("add_quest/lvl")+"的任务\n" );
                        return 1;
                        }
                else return notify_fail("指令格式：qlist [add|set <questlist>] \n");
                }
        if ( arg =="add" && me->query_temp("add_quest")) {
                init_var();
                write( "第一步\n======\n" );
                write( "请输入任务名称：" );
                input_to( (: do_add_list_name :) );
                }
        if ( sscanf(arg, "set %s.%d", owner, lvl) == 2 ) {
                me->set_temp("add_quest/owner", owner);
                me->set_temp("add_quest/lvl",lvl);
                write( "现在您可以开始添加"+arg[4..strlen(arg)]+"的任务\n" );
                }

        if ( sscanf(arg, "set %s", owner) == 1 ) {
                me->set_temp("add_quest/owner", owner);
                write( "现在您可以开始添加"+arg[4..strlen(arg)]+"的任务\n" );
                }

        return 1;
}

void init_var()
{
        item["name"]          = "";
        item["quest_type"]    = "";
        item["quest_time"]    = 0;
        item["exp"]           = 0;
        item["pot"]           = 0;
        item["time"]          = 0;
        item["quest_target"]  = "";
        item["quest_desc"]    = "";
        item["quest_objects"] = "";
}

void do_add_list_name(string arg)
{
        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }

        if ( !arg || !check_legal_arg(arg) ) {
                write( "[错误]任务名称为中文并且不能为空\n" );
                write( "请重新输入任务名称：" );
                input_to( (: do_add_list_name :) );
                return;
                }
      
        item["name"] = arg;
        write( "第二步\n======\n" );
        write( "请输入任务方式：" );
        input_to( (: do_add_list_type :) );
}

void do_add_list_type(string arg)
{
        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }
        if ( !arg || !check_legal_arg(arg) ) {
                write( "[错误]任务方式为中文并且不能为空\n" );
                write( "请输重新入任务方式：" );
                input_to( (: do_add_list_type :) );
                return;
                }
        if( member_array(arg, type) == -1 ) {
                write( "[错误]任务方式只允许为寻,杀,送,找\n" );
                write( "请重新输入任务方式：" );
                input_to( (: do_add_list_type :) );
                return;
                }

        item["quest_type"] = arg;
        write( "第三步\n======\n" );
        write( "请输入任务需要时间：" );
        input_to( (: do_add_list_time :) );
}

void do_add_list_time(string arg)
{
        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }

        if ( !arg || (sscanf (arg, "%d", item["quest_time"]) != 1) ) {
                write( "[错误]任务需要时间必须为数字\n" );
                write( "请重新输入任务需要时间：" );
                input_to( (: do_add_list_time :) );
                return;
                }
      
        write( "第四步\n======\n" );
        write( "请输入任务奖励经验值：" );
        input_to( (: do_add_list_exp :) );
}

void do_add_list_exp(string arg)
{
        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }

        if ( !arg || (sscanf (arg, "%d", item["exp"]) != 1) ) {
                write( "[错误]任务奖励经验必须为数字\n" );
                write( "请重新输入任务奖励经验值：" );
                input_to( (: do_add_list_exp :) );
                return;
                }
      
        write( "第五步\n======\n" );
        write( "如果任务为寻或杀则直接输入回车\n" );
        write( "如果任务为送则输入送到NPC的名称\n" );
        write( "如果任务为找则输入物品所在NPC的名称\n" );
        write( "请输入目标名称：" );
        input_to( (: do_add_list_target :) );
}

void do_add_list_target(string arg)
{
        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }

        item["quest_target"] = arg;
        write( "第六步\n======\n" );
        write( "如果任务为送或找则输入送或找的物品的描述\n" );
        write( "请输入物品的描述：" );
        input_to( (: do_add_list_desc :) );
}

void do_add_list_desc(string arg)
{
        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }

        item["quest_desc"] = arg;
        write( "第七步\n======\n" );
        write( "如果任务为送或找且物品为特殊物品\n" );
        write( "如/d/city/obj/jitui\n" );
        write( "请输入任务涉及的物品档案名称：" );
        input_to( (: do_add_list_object :) );
}

void do_add_list_object(string arg)
{
        mapping *lists;
        object qlist;

        if ( arg == "." ) {
                write ("你放弃本次添加。\n");
                return;
                }


        if ( arg !="" && !load_object(arg) ) {
                write( "[错误]您输入的物品档案不存在或非物品\n" );
                write( "请检查后输入任务涉及的物品档案名称：" );
                input_to( (: do_add_list_object :) );
                return;
                }

        item["quest_object"] = arg;
        item["time"] = time();

        qlist = new (QUEST_OB);
        if ( !qlist )
                return;
        qlist->set("quest_owner", this_player()->query_temp("add_quest/owner"));
        qlist->set("quest_lvl", this_player()->query_temp("add_quest/lvl"));
        qlist->restore();

        lists = qlist->query("list");
        if( !pointerp(lists) || !sizeof(lists) )
                lists = ({ item });
        else
                lists += ({ item });

        qlist->set("list", lists);
        qlist->set("total_quest", qlist->query("total_quest") + 1);
        qlist->last_updata(this_player()->name(1));
        qlist->save();
        destruct(qlist);
        write("添加完成。\n");
        return;
}

int check_legal_arg(string arg)
{
        int i, j;

        i = strlen(arg);
        
        if( i < 2 || i > 20 || i%2 ) {
                write("对不起，输入必须是一到十个汉字。\n");
                return 0;
        }
        while(i--) {
                if( arg[i]<=' ' ) {
                        write("对不起，不能使用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) {
                        write("对不起，您的输入必须是中文。\n");
                        return 0;
                }
        }
        return 1;
}
