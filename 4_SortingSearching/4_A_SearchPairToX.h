/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_A_SEARCHPAIRTOX_H
#define TEN_EIGHT_ALGORITHM_4_A_SEARCHPAIRTOX_H

void SearchPairToX(int* arr, int len, int sum)
{
    int res_x, res_y;

    int l = 0, r = len-1;
    int diff = INF;
    while (l < r)
    {
        if (abs(arr[l]+arr[r] - sum) < diff)
        {
            res_x = l;
            res_y = r;
            diff = abs(arr[l]+arr[r] - sum);
        }

        if (arr[l] + arr[r] > sum) r--;
        else l++;
    }

    cout << "Sum = "<<sum<<", Pair = <" << res_x << ", " << res_y << ">, diff = " << diff << endl;
}
#endif //TEN_EIGHT_ALGORITHM_4_A_SEARCHPAIRTOX_H
