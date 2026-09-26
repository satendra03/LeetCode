class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long massL = mass;
        for(int i=0; i<asteroids.length; i++) {
            if(massL < asteroids[i]) return false;
            massL += asteroids[i];
        }
        return true;
    }
}