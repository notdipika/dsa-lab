Warshall(w)
{
    m = w
    for k = 1 to n
    for i = 1 to n
    for j = 1 to n
    w[i][j] = w[i][j] or (w[i][k] and w[k][j])
}