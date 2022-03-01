static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class Solution {
public:
int strongPasswordChecker(string s)
{
    bitset<3> requirements{111}; // 0:lowercase, 1:uppercase, 2:number
    list<int> repeats;           // store length of repeated character sequences

    auto it = s.begin(); // 2 pointers to track length of repeated characters
    auto it2 = s.end();
    while (it != s.end())
    {
        if (*it != *it2) // TODO: skip checks when none left
        {
            if (requirements.test(0) && islower(*it))
                requirements.reset(0);
            if (requirements.test(1) && isupper(*it))
                requirements.reset(1);
            if (requirements.test(2) && isdigit(*it))
                requirements.reset(2);
        }
        else // fast forward through repeated characters
        {
            while (it != s.end() && *it == *it2)
                ++it;

            if (distance(it2, it) != 2)
                repeats.push_back(distance(it2, it));

            if (it != s.end())
                continue;
            else
                break;
        }
        it2 = it;
        ++it;
    }
    // sort all repeats. Runs of 3,6,9... at the front, followed by 4,7,10,... then 5,8,11...
    // to minimize deletes, just pick from the front
    repeats.sort([](const int &lhs, const int &rhs) { return (lhs % 3) < (rhs % 3); }); // while length>20 delete
    // while length<=20 replace
    // while length<6 insert
    int ans{0}, len{static_cast<int>(s.size())};
    while (len > 20)
    {
        if (!repeats.empty())
        {
            if (repeats.front() == 3)
            {
                repeats.pop_front();
            }
            else
            {
                --repeats.front();
                repeats.sort([](const int &lhs, const int &rhs) { return (lhs % 3) < (rhs % 3); });
            }

            ++ans;
            --len;
        }
        else
        {
            ans += len - 20;
            len = 20;
        }
    }

    // requirements: need min requirements.count() replace/inserts
    // triples: 1 replace for every repeats.top()/3 chars
    int rep_ins{0};
    while (!repeats.empty())
    {
        rep_ins += repeats.front() / 3;
        repeats.pop_front();
    }

    if ((len + rep_ins) < 6)
    {
        rep_ins += 6 - len - rep_ins;
    }
    ans += max(static_cast<int>(requirements.count()), rep_ins);

    return ans;
}
};
