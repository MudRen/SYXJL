// quest_list.c
// make by Luky
// �����Ϊ Ѱ,ɱ,��,��
// Ѱ: ��Ѱ��Ʒ�����ط������npc
// ɱ: ɱ��npc
// ��: ����Ʒ����һ����npc
// ��: �������npc�����ȥ��Ѱ��ָ��npc���ϵ�ָ����Ʒ,Ȼ�󽻻�

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

string *type = ({ "Ѱ", "ɱ", "��", "��" });

int main(object me,string arg)
{
        string owner;
        int lvl;

        me = this_player();
        if( !arg ) {
                if ( me->query_temp("add_quest") ) {
                        write( "����������ʼ���"+me->query_temp("add_quest/owner")+"."+ me->query_temp("add_quest/lvl")+"������\n" );
                        return 1;
                        }
                else return notify_fail("ָ���ʽ��qlist [add|set <questlist>] \n");
                }
        if ( arg =="add" && me->query_temp("add_quest")) {
                init_var();
                write( "��һ��\n======\n" );
                write( "�������������ƣ�" );
                input_to( (: do_add_list_name :) );
                }
        if ( sscanf(arg, "set %s.%d", owner, lvl) == 2 ) {
                me->set_temp("add_quest/owner", owner);
                me->set_temp("add_quest/lvl",lvl);
                write( "���������Կ�ʼ���"+arg[4..strlen(arg)]+"������\n" );
                }

        if ( sscanf(arg, "set %s", owner) == 1 ) {
                me->set_temp("add_quest/owner", owner);
                write( "���������Կ�ʼ���"+arg[4..strlen(arg)]+"������\n" );
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
                write ("�����������ӡ�\n");
                return;
                }

        if ( !arg || !check_legal_arg(arg) ) {
                write( "[����]��������Ϊ���Ĳ��Ҳ���Ϊ��\n" );
                write( "�����������������ƣ�" );
                input_to( (: do_add_list_name :) );
                return;
                }
      
        item["name"] = arg;
        write( "�ڶ���\n======\n" );
        write( "����������ʽ��" );
        input_to( (: do_add_list_type :) );
}

void do_add_list_type(string arg)
{
        if ( arg == "." ) {
                write ("�����������ӡ�\n");
                return;
                }
        if ( !arg || !check_legal_arg(arg) ) {
                write( "[����]����ʽΪ���Ĳ��Ҳ���Ϊ��\n" );
                write( "��������������ʽ��" );
                input_to( (: do_add_list_type :) );
                return;
                }
        if( member_array(arg, type) == -1 ) {
                write( "[����]����ʽֻ����ΪѰ,ɱ,��,��\n" );
                write( "��������������ʽ��" );
                input_to( (: do_add_list_type :) );
                return;
                }

        item["quest_type"] = arg;
        write( "������\n======\n" );
        write( "������������Ҫʱ�䣺" );
        input_to( (: do_add_list_time :) );
}

void do_add_list_time(string arg)
{
        if ( arg == "." ) {
                write ("�����������ӡ�\n");
                return;
                }

        if ( !arg || (sscanf (arg, "%d", item["quest_time"]) != 1) ) {
                write( "[����]������Ҫʱ�����Ϊ����\n" );
                write( "����������������Ҫʱ�䣺" );
                input_to( (: do_add_list_time :) );
                return;
                }
      
        write( "���Ĳ�\n======\n" );
        write( "����������������ֵ��" );
        input_to( (: do_add_list_exp :) );
}

void do_add_list_exp(string arg)
{
        if ( arg == "." ) {
                write ("�����������ӡ�\n");
                return;
                }

        if ( !arg || (sscanf (arg, "%d", item["exp"]) != 1) ) {
                write( "[����]�������������Ϊ����\n" );
                write( "��������������������ֵ��" );
                input_to( (: do_add_list_exp :) );
                return;
                }
      
        write( "���岽\n======\n" );
        write( "�������ΪѰ��ɱ��ֱ������س�\n" );
        write( "�������Ϊ���������͵�NPC������\n" );
        write( "�������Ϊ����������Ʒ����NPC������\n" );
        write( "������Ŀ�����ƣ�" );
        input_to( (: do_add_list_target :) );
}

void do_add_list_target(string arg)
{
        if ( arg == "." ) {
                write ("�����������ӡ�\n");
                return;
                }

        item["quest_target"] = arg;
        write( "������\n======\n" );
        write( "�������Ϊ�ͻ����������ͻ��ҵ���Ʒ������\n" );
        write( "��������Ʒ��������" );
        input_to( (: do_add_list_desc :) );
}

void do_add_list_desc(string arg)
{
        if ( arg == "." ) {
                write ("�����������ӡ�\n");
                return;
                }

        item["quest_desc"] = arg;
        write( "���߲�\n======\n" );
        write( "�������Ϊ�ͻ�������ƷΪ������Ʒ\n" );
        write( "��/d/city/obj/jitui\n" );
        write( "�����������漰����Ʒ�������ƣ�" );
        input_to( (: do_add_list_object :) );
}

void do_add_list_object(string arg)
{
        mapping *lists;
        object qlist;

        if ( arg == "." ) {
                write ("�����������ӡ�\n");
                return;
                }


        if ( arg !="" && !load_object(arg) ) {
                write( "[����]���������Ʒ���������ڻ����Ʒ\n" );
                write( "��������������漰����Ʒ�������ƣ�" );
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
        write("�����ɡ�\n");
        return;
}

int check_legal_arg(string arg)
{
        int i, j;

        i = strlen(arg);
        
        if( i < 2 || i > 20 || i%2 ) {
                write("�Բ������������һ��ʮ�����֡�\n");
                return 0;
        }
        while(i--) {
                if( arg[i]<=' ' ) {
                        write("�Բ��𣬲���ʹ�ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) {
                        write("�Բ�������������������ġ�\n");
                        return 0;
                }
        }
        return 1;
}
